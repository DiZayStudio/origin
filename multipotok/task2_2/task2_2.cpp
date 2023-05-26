#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <mutex>
#include <conio.h>

std::mutex m;
int* sum;

void setXY(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<int> x1;

    sum = 0;
    // Длина расчёта
    const long n = 10000;
    // Количество потоков
    int n_thread = 4;
    int interval = 5;
    int shag = 20;

    for (int i = 0; i < n; i++) {
        x1.push_back(i);
    }

    std::vector<std::thread> thr;
    using namespace std::chrono_literals;

    for (int i = 0; i < n_thread; i++) {
        thr.push_back(std::thread([=]() {
            
            auto start = std::chrono::steady_clock::now();

            m.lock();
            setXY(0, i*interval);
            std::cout << "Номер потока: " << i << std::endl;
            std::cout << "Идентификатор потока: " << std::this_thread::get_id << std::endl;
            m.unlock();
            int n1 = (i) * n / n_thread;
            int n2 = (i + 1) * n / n_thread - 1;
            int delta = (n2 - n1) / shag;
            
            m.lock();
            setXY(0, i * interval + 2);
            std::cout << "[";

            setXY(shag+3, i * interval + 2);
            std::cout << "]" << std::endl;
            m.unlock();
            
            int position = 2;
            for (int j = n1+1; j < n2; j++) {
                    sum += x1[j];
                 
                if (j % delta == 0) {
                    m.lock();
                    setXY(position, i * interval + 2);
                    std::cout << "=";
                    m.unlock();
                    position += 1;
                }
                std::this_thread::sleep_for(2us);
            }

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> el_time = end - start;

            m.lock();
            setXY(0, i * interval + 3);
            std::cout << "Время работы потока: " << el_time.count() << " ms." << std::endl;
            std::cout << std::endl;
            m.unlock();
        }
            ));
    }

    for (auto& f : thr) {
        f.join();
    }
    setXY(0, n_thread * interval);
}
