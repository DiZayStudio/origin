#include <iostream>
#include <vector>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <condition_variable>

const int n[4] = { 1000, 10000, 100000, 1000000 };
int n_thread = 1;

std::vector<int> x1, x2, y;
std::once_flag flag;

void print_kol_yader() {
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    std::cout << std::endl;
    std::cout << "\t\t" << n[0] << "\t\t" << n[1] << "\t\t" << n[2] << "\t\t" << n[3] << std::endl;
}

void print_N_potokov() {
    std::cout << n_thread << " потоков \t";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    while (n_thread < 20)
    {
        std::once_flag flag2;
        for (int i2 = 0; i2 < 4; i2++) {
            for (int i = 0; i < n[i2]; i++) {
                x1.push_back(i);
                x2.push_back(i * 10);
            }
            y.resize(n[i2], 0);

            auto start = std::chrono::steady_clock::now();

            std::vector<std::thread> thr;
            for (int i = 0; i < n_thread; i++) {
                thr.push_back(std::thread([&]() {
                    call_once(flag, print_kol_yader);
                    call_once(flag2, print_N_potokov);
                    int n1 = (i - 1) * n[i2] / n_thread;
                    int n2 = (i)*n[i2] / n_thread - 1;
                    for (int j = n1; j < n2; j++) {
                        y[j] = x1[j] + x2[j];
                    }
                }
                ));
            }

            for (auto& f : thr) {
                f.join();
            }

            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> el_time = end - start;
            std::cout << el_time.count() << " ms. \t";

        }
        std::cout << std::endl;
        n_thread *= 2;
    }
}
