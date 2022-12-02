#include <iostream>
#include <Windows.h>
#include <string>
#include <exception>

class Bad_length : public std::exception {
private:
    std::string bad_length;
public:
    Bad_length(std::string error) : bad_length(error){}

    const char* what() {
        return bad_length.c_str();
    }
};

int function(std::string str, int forbidden_length){
    int size = str.length();
    if (size != forbidden_length) return size;
    else throw Bad_length("Вы ввели слово запретной длины! До свидания");
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    std::string str;

    try {
        do {
            std::cout << "Введите слово: ";
            std::cin >> str;
 
            int size = function(str, forbidden_length);
            std::cout << "Длина слова \"" << str << "\" равна " << size << std::endl;
        } while (true);
    }
    catch (Bad_length& bad_length) {
        std::cout << bad_length.what() << std::endl;
    }  
}
