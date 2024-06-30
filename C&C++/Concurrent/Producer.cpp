/*
 * @Description:
 * @Version: 1.0
 * @Author: daLao
 * @Email:  
 * @Date: 2022-11-19 22:04:55
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-06-28 22:30:45
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <atomic>

int main(void)
{
    std::queue<int> production;

    std::mutex mtx;
    std::condition_variable cv;

    // 是否有产品可供消费
    bool ready = false;

    // 生产结束
    bool done = false;

    std::thread producer(
        [&]() -> void
        {
            for (int i = 1; i < 10; ++i)
            {
                // 模拟实际生产过程
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                std::cout << "producing " << i << std::endl;

                std::unique_lock<std::mutex> lock(mtx);
                production.push(i);

                // 有产品可以消费
                ready = true;
                cv.notify_one();
            }
            // 生产结束
            done = true;
        });

    std::thread consumer(
        [&]() -> void
        {
            std::unique_lock<std::mutex> lock(mtx);
            // 如果生成没有结束或者队列中还有产品没有消费, 则继续消费, 否则结束消费
            while (!done || !production.empty())
            {
                // 防止误唤醒
                while (!ready)
                {
                    cv.wait(lock);
                }

                while (!production.empty())
                {
                    // 模拟消费过程
                    std::cout << "consuming " << production.front() << std::endl;
                    production.pop();
                }

                // 没有产品了
                ready = false;
            }
        });

    producer.join();
    consumer.join();

    return 0;
}