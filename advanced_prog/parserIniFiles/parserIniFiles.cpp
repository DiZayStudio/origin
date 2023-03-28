#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <windows.h>

//template <class T> 
class ini_parser {
private:
    std::map<std::string, int> sections;

public:
    ini_parser(std::string filename) {
        std::string line;
        // окрываем файл для чтения
        std::ifstream iniFiles(filename);
        if (iniFiles.is_open()) {
            while (getline(iniFiles, line)) {
                std::cout << line << std::endl;
            }
        }
        iniFiles.close();
    }
    ~ini_parser() {}


 //   T get_value(std::string name) {
 //       return 0;
 //   }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    ini_parser parser("config.ini");

 //   auto value = parser.get_value<int>("section.value");

    std::cout << "Приметлсаd!\n";
}