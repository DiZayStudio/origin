#include <iostream>
#include <map>


void PrintMap(const std::map<char, int> m) {
      
    std::multimap<int, char> revers_m;
        for (const auto& element : m) {
            revers_m.insert({ element.second, element.first });
        }
     
        for (auto iter = revers_m.end(); iter != revers_m.begin();) {
            iter--;
            std::cout << iter->second << ": " << iter->first << std::endl;
        }
}

void counting_char(std::string str) {

    std::map<char, int> M;

    for (char symbol : str) {
        if (M.empty()) {
            M.insert({ symbol, 1 });
        }
        else {
            if (M.find(symbol) == M.end()) {
                M.insert({ symbol, 1 });
            }
            else {
                M[symbol] += 1;
            }
        }
    }

    PrintMap(M);
}


int main()
{
    std::string SearchString = "Hello world!!";

    std::cout << "[IN]: " << SearchString << std::endl;
    std::cout << "[OUT]: " << std::endl;

    counting_char(SearchString);
}

