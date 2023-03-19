#include <iostream>
#include <vector>


template<class T>
void move_vectors(std::vector<T>& lhs, std::vector<T>& rhs) {
    std::vector<T> temp = std::move(lhs);
    lhs = std::move(rhs);
    rhs = std::move(temp);
}

int main()
{ 
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    move_vectors(one, two);

    std::cout << "one: \t" ;
    for (auto temp : one)
        std::cout << temp << "\t";
    std::cout << std::endl;
    std::cout << "two: \t";
    for (auto temp : two)
        std::cout << temp << "\t";

}
