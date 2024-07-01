/*
 * @Description:
 * @Version: 1.0
 * @Author:
 * @Email:
 * @Date: 2024-06-30 18:20:32
 * @LastEditors:
 * @LastEditTime: 2024-06-30 18:20:38
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

static const int MAX = 10e8;
static double gSum = 0;

static std::mutex gMutex;

void ConcurrentWorker(int min, int max)
{
    double v = 0;
    for (int i = min; i <= max; i++)
    {
        v += sqrt(i);
    }

    std::lock_guard<std::mutex> m(gMutex);
    gSum += v;
}

void ConcurrentTask(int min, int max)
{
    unsigned concurrentCount = std::thread::hardware_concurrency();
    std::cout << "hardware_concurrency: " << concurrentCount << std::endl;

    std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

    std::vector<std::thread> threads;
    for (int i = 0; i < concurrentCount; i++)
    {
        int _max = max / concurrentCount * (i + 1);
        threads.push_back(std::thread(ConcurrentWorker, min, _max));
        min = _max + 1;
    }

    for (int i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }

    std::chrono::steady_clock::time_point endTime = std::chrono::steady_clock::now();
    double ms = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Concurrent task finish, " << ms << " ms consumed, Result: " << gSum << std::endl;
}

int main(void)
{
    ConcurrentTask(0, MAX);

    return 0;
}