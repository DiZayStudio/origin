#include <iostream>
#include <vector>


template<class T>
void move_vectors(std::vector<T>* last, std::vector<T>* first) {
    for (int i = 0; i < *first.size;i++) {
        *last[i] = *first[i];
    }
}

int main()
{
    
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(&two, &one);
    std::cout << "Hello World!\n";
}
