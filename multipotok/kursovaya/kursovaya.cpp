#include <thread>
#include <chrono>
#include <queue>
#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>

using namespace std::chrono_literals;

void F1()
{
    std::cout << "функция F1" << std::endl;
}
void F2()
{
    std::cout << "функция F2" << std::endl;
}

template<class T>
class Safe_queue {
protected:
 //   std::condtional_variables;
    std::queue<std::function<void()>> work_queue;
    std::mutex m;
public:
    void push(T func) {
        m.lock;
        work_queue.push(func);
        m.unlock;
    };
    void pop() {
        m.lock;
        work_queue.pop();
        m.unlock;
    };
    T front() {
        m.lock;
        T res = work_queue.front();
        m.unlock;
        return res;
    };
    bool empty() {
        m.lock;
        bool b = work_queue.empty();
        m.unlock;
        return b;
    }
};

class Thread_pool {
public:
    std::vector<std::thread> threads;
    Safe_queue<std::function<void()>> safe_queue;
    bool done = false;
    std::mutex m2;
public:
    Thread_pool() {
        const int pool_size = std::thread::hardware_concurrency() - 2;
        for (size_t i = 0; i < pool_size; i++) {
            threads.push_back(std::thread(work));
        }
        for (size_t i = 0; i < pool_size; i++) {
            if (threads[i].joinable())
            {
                threads[i].join();
            }
        }
    
    };
    ~Thread_pool() {
        for (size_t i = 0; i < threads.size(); i++)
        {
            threads.pop_back();
        }
    };

    void work() {
        m2.lock();
        std::cout << "id:" << std::this_thread::get_id() << std::endl;
        m2.unlock();
        while (!done)
        {
            std::function<void()> task;
            if (!safe_queue.empty())
            {
                task = safe_queue.front();
                std::this_thread::sleep_for(500ms);
                task();
                safe_queue.pop();
            }
            else
            {
                std::this_thread::yield();
            }
        }   
    };

    void submit(std::function<void()> func) {
        safe_queue.push(func);
        done = true;
    }

};

void add_function(Thread_pool& thr_pool) {
    for (size_t i = 0; i < 5; i++)
        {
            std::this_thread::sleep_for(1s);
            thr_pool.submit(F1);
            thr_pool.submit(F2);
        }
}


int main(){

    Thread_pool thr_pool;

    std::thread add_function(thr_pool);

    add_function.join();

    return 0;
} 