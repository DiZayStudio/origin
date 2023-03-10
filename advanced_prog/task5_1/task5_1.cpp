#include <iostream>
#include <vector>

template <class T>
T square(const T a) {
    return a * a;
}

template <class T>
std::vector <T> square(const std::vector <T> a) {

    std::vector<T> temp(a.size());

    for (auto i = 0; i < temp.size(); i++) {
        temp[i] = a[i]*a[i] ;
    }
    return temp;
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

