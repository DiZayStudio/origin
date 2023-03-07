#include <iostream>
#include <vector>

template <class T>
void print_square(T a) {
    std::cout << "[OUT]: " << a * a;
}

template <>
void print_square(std::vector <int> a) {
    std::cout << "[OUT]:";
    for(int num : a ) {
        std::cout << " " << num * num;
    }
    
}

int main()
{
    int num = 4;
    std::cout << "[IN]: " << num << std::endl;

    print_square(num);
    std::cout << std::endl;

    std::vector<int> v = { -1, 4, 8 };   
    std::cout << "[IN]:";
    for (int num : v) {
        std::cout << " " << num;
    }
    std::cout << std::endl;

    print_square(v);
}

