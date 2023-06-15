#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <queue>
#include <iostream>
#include <functional>
using namespace std;
mutex m;
bool done = false;
queue<std::function<void()>> work_queue;
std::vector<std::thread> threads;

void F1()
{
    this_thread::sleep_for(20ms);
    cout << "F1" << endl;
}
void F2()
{
    this_thread::sleep_for(20ms);
    cout << "F2" << endl;
}
void addF1()
{
    for (size_t i = 0; i < 5; i++)
    {
        this_thread::sleep_for(0.5s);
        work_queue.push(F1);
    }
    //done = true;
}

void addF2()
{
    for (size_t i = 0; i < 5; i++)
    {
        this_thread::sleep_for(1s);
        work_queue.push(F2);
    }
    done = true;
}

void work()
{
    m.lock();
    cout << "id:" << this_thread::get_id() << endl;
    m.unlock();
    while (!done)
    {
        function<void()> task;
        if (!work_queue.empty())
        {
            task = work_queue.front();
            task();
            work_queue.pop();
        }
        else
        {
            this_thread::yield();
        }
    }
}


int main()
{
    const int pool_size = thread::hardware_concurrency() - 2;
    thread add1(addF1);
    thread add2(addF2);
    for (size_t i = 0; i < pool_size; i++)
    {
        threads.push_back(thread(work));
    }
    for (size_t i = 0; i < pool_size; i++)
    {
        if (threads[i].joinable())
        {
            threads[i].join();
        }
    }
    add1.join();
    add2.join();
    return 0;
}