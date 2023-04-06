#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <windows.h>

class FileNotFound : public std::exception {
public:
    const char* what() const override { return "Warning! Файл не найден"; }
};

class ErrorVar : public std::exception {
public:
    const char* what() const override { return "Warning! Значение переменной отсутствует"; }
};
class ErrorSintax : public std::exception {
public:
    const char* what() const override { return "Error! Синтаксическая ошибка в строке "; }
};

class ini_parser {
private:
    // std::map<std::string, &std::map> sections;
    std::string _FileName;
    std::string _section;
    std::string _var;
    std::map<std::string, std::string> v;

public:
    ini_parser(const std::string filename) { 
        this->_FileName = filename;
    }
    ~ini_parser() {  }

    template <class T>
    T get_value(std::string name) {
        std::string line;

        //поиск положения разделителя
        std::size_t npos = name.find(".");
        //получение подстроки
        this->_section = name.substr(0, npos); 
        this->_var = name.substr(npos+1, name.length());
        
        //открываем файл
        std::ifstream iniFiles(this->_FileName);
        // номер строки
        int num_line = 0;
        bool coincidence = false;
        
        if (iniFiles.is_open()) {
            while (getline(iniFiles, line)) {
                //поиск начала названия секции
                std::size_t position_l = line.find("[");
                if (position_l < line.length()) {
                    //поиск конца названия секции
                    std::size_t position_r = line.find("]");
                    if (position_r < line.length()) {
                        //проверяем совпадение названия секции
                        if (this->_section == line.substr(position_l + 1, position_r - position_l - 1)) {
                            std::cout << "Секция найдена. Начало в строке: " << num_line+1 << std::endl;
                            num_line++;
                            coincidence = true;
                                continue;
                        }
                        else {
                            coincidence = false;
                        }
                    } else throw ErrorSintax();
                }
                // если секция соответствует, считываем переменные
                if (coincidence) {
                    std::string var = "";
         
                    for (int i = 0; i < line.length();i++) {
                    // убираем пробелы
                      //  if (line[i] != ' ') {
                            if (line[i] == ';') {
                                break;  // исключаем комментарии
                            }
                         var += line[i];
                      //  }
                    }
                    if (var != "") {
                        //поиск положения разделителя
                        int npos = var.find("=");
                        v[var.substr(0, npos)] = var.substr(npos + 1, var.length());
                    }
                }
                num_line++;
            }
            iniFiles.close();
        }
        else
            throw FileNotFound();
              
        //проверка наличия переменной в секции
        auto search = v.find(this->_var);
        if (search == v.end()) {
            std::cout << "Такой переменной в ["<< this->_section << "] нет. Зато имеются следующие переменные : " << std::endl;
    
        for (const auto& s : v)
            std::cout << s.first << std::endl;
       }

        // проверка наличия значения переменной
        if (v[this->_var] == "") {
            throw ErrorVar();
        }

        std::string znachenie = v[this->_var];
        //возврат значения переменной
        if (typeid(T) == typeid(int)) 
            return stoi(znachenie);
        if (typeid(T) == typeid(double)) 
            return stod(znachenie);
     //   if (typeid(T) == typeid(std::string))
     //       return znachenie;
    }
};


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    try {
        ini_parser parser("config.ini");

     //   auto value = parser.get_value<double>("Section1.var1");
     //   auto value = parser.get_value<int>("Section1.var1");
     //   auto value = parser.get_value<std::string>("Section2.var2");
        auto value = parser.get_value<int>("Section4.Mode");

        std::cout << "Значение искомой переменной = " << value << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

  
}