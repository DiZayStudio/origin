#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <mutex>

std::mutex m;
int* sum;

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int> x1;

    sum = 0;
    // Длина расчёта
    const long n = 10000;
    // Количество потоков
    int n_thread = 4;

    for (int i = 0; i < n; i++) {
        x1.push_back(i);
    }

    std::vector<std::thread> thr;
    using namespace std::chrono_literals;

    for (int i = 0; i < n_thread; i++) {
        thr.push_back(std::thread([=]() {
            
            auto start = std::chrono::steady_clock::now();

            m.lock();

            std::cout << "Номер потока: " << i << std::endl;
            std::cout << "Идентификатор потока: " << std::this_thread::get_id << std::endl;

            int n1 = (i) * n / n_thread;
            int n2 = (i+1)*n / n_thread - 1;
            int delta = (n2 - n1) / 20;

            std::cout << "[";
            for (int j = n1; j < n2; j++) {
                    sum += x1[j];

                if (j % delta == 0) {
                    std::cout << "=";
                }
                std::this_thread::sleep_for(2us);
            }
            std::cout << "]" << std::endl;
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> el_time = end - start;

            std::cout << "Время работы потока: " << el_time.count() << " ms." << std::endl;

            std::cout << std::endl;
            m.unlock();
        }
            ));
    }

    for (auto& f : thr) {
        f.join();
    }
}
