#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#include <Windows.h>

using namespace std::chrono_literals;

void F1() { std::cout << "функция F1" << std::endl; }
void F2() { std::cout << "функция F2" << std::endl; }

template <class T> class Safe_queue {
protected:
    //   std::condtional_variables;
    std::queue<std::function<void()>> work_queue;
    std::mutex m;
public:
    void push(T func) {
        std::lock_guard<std::mutex> lock(m);
        work_queue.push(func);
    };
    void pop() {
        std::lock_guard<std::mutex> lock(m);
        work_queue.pop();
    };
    T front() {
        std::lock_guard<std::mutex> lock(m);
        T res = work_queue.front();
        return res;
    };
    bool empty() {
        std::lock_guard<std::mutex> lock(m);
        bool b = work_queue.empty();
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
        const int pool_size = std::thread::hardware_concurrency() - 1;
        for (size_t i = 0; i < pool_size; i++) {
            threads.push_back(std::thread(&Thread_pool::work, this));
        }
    };

    ~Thread_pool() {
        for (size_t i = 0; i < threads.size(); i++) {
            threads.pop_back();
        }
    };

    void work() {
        m2.lock();
        std::cout << "id:" << std::this_thread::get_id() << std::endl;
        m2.unlock();
        std::function<void()> task;
        while (!done) {           
            if (!safe_queue.empty()) {
                std::this_thread::sleep_for(1s);
                task = safe_queue.front();
            
                m2.lock();
                task();
                m2.unlock();
                safe_queue.pop();
            }
            else {
                std::this_thread::yield();
                done = true;
                std::cout << std::this_thread::get_id() <<  " остановился" << std::endl;
            }
        }
    };

    void submit(std::function<void()> func) {
        safe_queue.push(func);
    }
};

void add_function(Thread_pool* thr_pool) {
    for (size_t i = 0; i < 4; i++) {
        (*thr_pool).submit(F1);
        (*thr_pool).submit(F2);
        std::this_thread::sleep_for(1s);
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Thread_pool thr_pool;

    std::thread th(add_function, &thr_pool);
    
    th.join();
    
    for (size_t i = 0; i < thr_pool.threads.size(); i++) {
        if (thr_pool.threads[i].joinable()) {
            thr_pool.threads[i].join();
        }
    }

    return 0;
}