// *C++和posix接口实现一个线程池
//-三个组件：任务队列, 执行队列, 线程池(中枢管理）

#include <iostream>
#include <deque>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//-打印线程错误专用, 根据err来识别错误信息
static inline void ERR_EXIT_THREAD(int err, const char *msg)
{
    fprintf(stderr, "%s:%s\n", strerror(err), msg);
    exit(EXIT_FAILURE);
}

class ThreadPool; //-声明

//- 任务队列元素
class TaskElement
{
public:
    void (*mCallBack)(void *arg);

    std::string mUserData;

    void setFunc(void (*tcb)(void *arg))
    {
        mCallBack = tcb;
    }
};

//-执行队列元素
class ExecElement
{
public:
    pthread_t mTid;

    ThreadPool *mPool;

    bool mIsAble = true;
    static void *start(void *arg);
};

//-线程池
class ThreadPool
{
public:
    //-任务队列和执行队列
    std::deque<TaskElement *> mTaskQueue;
    std::deque<ExecElement *> mExecQueue;

    //-条件变量
    pthread_cond_t mCond;
    //-互斥锁
    pthread_mutex_t mMutex;

    //-线程池大小
    int mCount;

    //-构造函数
    ThreadPool(int mCount) : mCount(mCount)
    {
        //-初始化条件变量和互斥锁
        pthread_cond_init(&mCond, nullptr);
        pthread_mutex_init(&mMutex, nullptr);
    }

    void Create()
    {
        //-初始执行队列
        for (int i = 0; i < mCount; ++i)
        {
            ExecElement *exec = new ExecElement;
            exec->mPool = const_cast<ThreadPool *>(this);
            int ret = pthread_create(&(exec->mTid), nullptr, exec->start, exec);
            if (ret)
            {
                delete exec;
                ERR_EXIT_THREAD(ret, "pthread_create");
            }
            fprintf(stdout, "create thread %d\n", i);
            mExecQueue.push_back(exec);
        }
        fprintf(stdout, "create mPool finish...\n");
    }

    // 加入任务
    void PushTask(void (*tcb)(void *arg), int i)
    {
        TaskElement *task = new TaskElement;
        task->setFunc(tcb);
        task->mUserData = "Task " + std::to_string(i) + " run in thread ";

        //-加锁
        pthread_mutex_lock(&mMutex);
        mTaskQueue.push_back(task);

        //-通知执行队列中的一个进行任务
        pthread_cond_signal(&mCond);
        //-解锁
        pthread_mutex_unlock(&mMutex);
    }

    //-销毁线程池
    ~ThreadPool()
    {
        for (int i = 0; i < mExecQueue.size(); ++i)
        {
            mExecQueue[i]->mIsAble = false;
        }

        pthread_mutex_lock(&mMutex);
        //-清空任务队列
        mTaskQueue.clear();

        //-广播给每个执行线程令其退出(执行线程破开循环会free掉堆内存)
        pthread_cond_broadcast(&mCond);
        pthread_mutex_unlock(&mMutex); //-让其他线程拿到锁

        //-等待所有线程退出
        for (int i = 0; i < mExecQueue.size(); ++i)
        {
            pthread_join(mExecQueue[i]->mTid, nullptr);
        }

        //-清空执行队列
        mExecQueue.clear();

        //-销毁锁和条件变量
        pthread_cond_destroy(&mCond);
        pthread_mutex_destroy(&mMutex);
    }
};

void *ExecElement::start(void *arg)
{
    //-获得执行对象
    ExecElement *exec = (ExecElement *)arg;
    while (true)
    {
        //-加锁
        pthread_mutex_lock(&(exec->mPool->mMutex));
        while (exec->mPool->mTaskQueue.empty())
        {
            //-如果任务队列为空, 等待新任务
            if (!exec->mIsAble)
            {
                break;
            }
            pthread_cond_wait(&exec->mPool->mCond, &exec->mPool->mMutex);
        }

        if (!exec->mIsAble)
        {
            pthread_mutex_unlock(&exec->mPool->mMutex);
            break;
        }

        TaskElement *task = exec->mPool->mTaskQueue.front();
        exec->mPool->mTaskQueue.pop_front();

        //-解锁
        pthread_mutex_unlock(&(exec->mPool->mMutex));

        //-执行任务回调
        task->mUserData += to_string(pthread_self());
        task->mCallBack(task);
    }
    //-删除线程执行对象
    delete exec;
    fprintf(stdout, "destroy thread %ld\n", pthread_self());
    return nullptr;
}

//-线程执行的业务函数
void execFunc(void *arg)
{
    TaskElement *task = (TaskElement *)arg;
    fprintf(stdout, "%s\n", task->mUserData.c_str());
};

int main()
{
    //-创建线程池
    ThreadPool mPool(10);

    mPool.Create();
    //-创建任务
    for (int i = 0; i < 20; ++i)
    {
        mPool.PushTask(&execFunc, i);
    }
    exit(EXIT_SUCCESS);
}