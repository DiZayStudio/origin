#include <iostream>
#include <algorithm>
#include <vector>



int main()
{
    std::vector<int> v{ 1, 1, 2, 5, 6, 1, 2, 4 };
    std::cout << "[IN]: ";
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";

    std::sort(v.begin(), v.end()); 
    auto last = std::unique(v.begin(), v.end());

    v.erase(last, v.end());

    std::cout << "[OUT]: ";
    for (int i : v)
        std::cout << i << " ";
    std::cout << "\n";
}