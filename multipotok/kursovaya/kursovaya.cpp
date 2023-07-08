#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <Windows.h>

using namespace std::chrono_literals;

void F1() {
    std::cout << "функция F1" << std::endl;
}
void F2() {
    std::cout << "функция F2" << std::endl;
}

template <class T>
class Safe_queue {
protected:
    std::condition_variable cond;
    std::queue<std::function<void()>> work_queue;
    std::mutex m;
public:
    void push(T func) {
        std::unique_lock<std::mutex> lock(m);
        work_queue.push(func);
        lock.unlock();
        cond.notify_one();
    };
    T pop() {
        std::unique_lock<std::mutex> lock(m);
        cond.wait(lock);
        T item = work_queue.front();
        work_queue.pop();
        return item;
    };
    bool empty() {
        std::unique_lock<std::mutex> lock(m);
        bool b = work_queue.empty();
        return b;
    };
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
            if (threads[i].joinable()) {
                threads[i].join();
            }
        }
        for (size_t i = 0; i < threads.size(); i++) {
            threads.pop_back();
        }
    };

    void work() {
        m2.lock();
        std::cout << "id:" << std::this_thread::get_id() << std::endl;
        m2.unlock();

        while (!safe_queue.empty()) {
            std::function<void()> task;
            task = safe_queue.pop();
            task();
        }
    };

    void submit(std::function<void()> func) {
        safe_queue.push(func);
    }
};

void add_function(Thread_pool* thr_pool) {
    for (size_t i = 0; i < 5; i++) {
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

    return 0;
}