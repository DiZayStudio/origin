#include <iostream>
#include <vector>

template <class T>
T square(const T a) {
    return a * a;
}

template <class T>
std::vector <T> square(std::vector <T> a) {

    for (auto i = 0; i < a.size(); i++) {
        a[i] = a[i] * a[i];
    }
    return a;
}


int main()
{
    int num = 4;
    std::cout << "[IN]: " << num << std::endl;
    std::cout << "[OUT]: ";
    std::cout << square(num) << std::endl;
    
    std::vector<int> v = { -1, 4, 8 };   
    
    std::cout << "[IN]:";
    for (int num : v) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    std::vector <int> c = square(v);

    std::cout << "[OUT]:";
    for (int num : c) {
        std::cout << " " << num;
    }
}

