#include <iostream>
#include <thread>
#include <Windows.h>
#include <chrono>


// 1й поток
void Client(int &countCl, int maxC) {

   while (countCl < maxC) {
       using namespace std::chrono_literals;
       std::this_thread::sleep_for(1000ms);

       ++countCl;
       std::cout << "В очереди: " << countCl << std::endl;
    }
}
// 2й поток
void Operator(int &countCl) {
    while (countCl > 0) {
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2000ms);

        --countCl;
        std::cout << "В очереди: " << countCl << std::endl;
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");

    int countClients = 1;
    int maxCount = 10;

    auto start = std::chrono::steady_clock::now();
    
    std::cout << "Количество ядер: " << std::thread::hardware_concurrency() << std::endl;

    std::thread f1(Client, std::ref(countClients), maxCount);
    std::thread f2(Operator, std::ref(countClients));
    f1.join();
    f2.join();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> el_time = end - start;

    std::cout << el_time.count() << " ms." << std::endl;
}
