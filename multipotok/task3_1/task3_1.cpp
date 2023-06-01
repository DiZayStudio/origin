#include <iostream>
#include <vector>
#include <random>
#include <Windows.h>
#include <future>

void serch_min(std::vector<int> v, int i_start, std::promise<int> m_index) {
    int min = INT_MAX;
    int index = 0;
    for (int i = i_start; i < v.size(); i++) {
        if (v.at(i) < min) {
            min = v.at(i);
            index = i;
        }          
    }
    m_index.set_value(index);
}

void main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> vec;
    const long n = 10;

    for (int i = 0; i < n; i++) {
        vec.push_back(rand());
    }
    std::cout << "Массив до сортировки:" << std::endl;
    for (auto v : vec) std::cout << v << "\t";
    std::cout << std::endl;

    for (int i = 0; i < vec.size(); i++) {
        std::promise<int> res_promise;
        std::future<int> res = res_promise.get_future();
        auto serch = std::async(serch_min, vec, i, std::move(res_promise));
        res.wait();
        int ind_min = res.get();
        if (i != ind_min) {
            int tmp = vec.at(i);
            vec.at(i) = vec.at(ind_min);
            vec.at(ind_min) = tmp;
        }
    }

    std::cout << "Массив после сортировки:" << std::endl;
    for (auto v : vec)
    std::cout << v << "\t";
    std::cout << std::endl;
}
