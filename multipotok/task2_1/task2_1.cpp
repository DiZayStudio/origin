#include <iostream>
#include <thread>
#include <Windows.h>
#include <chrono>
#include <atomic>

std::atomic<int> countCl(1);

// 1й поток
void Client(int maxC) {

   while (countCl.load() < maxC) {
       using namespace std::chrono_literals;
       std::this_thread::sleep_for(1000ms);

       ++countCl;
       std::cout << "В очереди: " << countCl << std::endl;
    }
}
// 2й поток
void Operator() {
    while (countCl.load() > 0) {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2000ms);

        --countCl;
        std::cout << "В очереди: " << countCl << std::endl;
    } 
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int maxCount = 5;

    auto start = std::chrono::steady_clock::now();
    
    std::thread f1(Client, maxCount);
    std::thread f2(Operator);
    f1.join();
    f2.join();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> el_time = end - start;

    std::cout << el_time.count() << " ms." << std::endl;
}
