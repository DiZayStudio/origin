#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <Windows.h>
using namespace std::chrono_literals;


class Data{
private:
    int n;
    double d;
    bool b;
public:
    Data(int n, double d, bool b) {
        this->n = n;
        this->d = d;
        this->b = b;
    }
    void Set_n(int n) {
        this->n = n;
    }
    void Set_d(double d) {
        this->d = d;
    }
    void Set_b(bool b) {
        this->b = b;
    }

    int Get_n() {
        return this->n;
    }
    double Get_d() {
        return this->d;
    }
    bool Get_b() {
        return this->b;
    }

    void print() {
        std::cout << "n = " << n << ", d = " << d << ", b = " << b << std::endl;
    }
    
    std::mutex m;
};

void swap1(Data& a, Data& b) {

    std::lock_guard<std::mutex> lm1{ a.m };
    std::lock_guard<std::mutex> lm2{ b.m };

    int tmp = a.Get_n();
    a.Set_n(b.Get_n());
    b.Set_n(tmp);

    double tmp1 = a.Get_d();
    a.Set_d(b.Get_d());
    b.Set_d(tmp1);

    bool tmp2 = a.Get_b();
    a.Set_b(b.Get_b());
    b.Set_b(tmp2);
}

void swap2(Data &a, Data &b) {

    std::scoped_lock sm(a.m, b.m);

    int tmp = a.Get_n();
    a.Set_n(b.Get_n());
    b.Set_n(tmp);

    double tmp1 = a.Get_d();
    a.Set_d(b.Get_d());
    b.Set_d(tmp1);

    bool tmp2 = a.Get_b();
    a.Set_b(b.Get_b());
    b.Set_b(tmp2);
}

void swap3(Data& a, Data& b) {

    std::unique_lock lock1{ a.m, std::defer_lock };
    std::unique_lock lock2{ b.m, std::defer_lock };

    std::lock(lock1, lock2);

    int tmp = a.Get_n();
    a.Set_n(b.Get_n());
    b.Set_n(tmp);

    double tmp1 = a.Get_d();
    a.Set_d(b.Get_d());
    b.Set_d(tmp1);

    bool tmp2 = a.Get_b();
    a.Set_b(b.Get_b());
    b.Set_b(tmp2);
}

int main()
{
    Data x1(1, 3.14, true), x2(2, 6.28, false);
    x1.print();
    x2.print();

    swap1(x1, x2);

    x1.print();
    x2.print();

    swap2(x1, x2);

    x1.print();
    x2.print();

    swap3(x1, x2);

    x1.print();
    x2.print();
}
