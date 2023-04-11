#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <windows.h>
#include <vector>

class MyException :public std::exception {
private:
    int num_line = 0;
public:
    MyException(const char *msg, int num):std::exception(msg){
        this->num_line = num + 1;
    }
    int getNum_line() {
        return this->num_line;
    }
};


class ini_parser {
private:
    std::string _FileName;
    std::string _section;
    std::string _var;
    std::map<std::string, std::string> v;
    std::vector<std::string> stroka;
public:
    ini_parser(const std::string filename) { 
        this->_FileName = filename;
        //открываем файл
        std::ifstream iniFiles(this->_FileName);
        std::string temp;
        if (iniFiles.is_open()) {
            //считываем строки
            while (getline(iniFiles, temp)) {
                stroka.push_back(temp);
            }
            if(stroka.empty()) throw std::exception("Файл пустой");
        }
        else throw std::exception("Файл не найден");

        //закрываем файл
        iniFiles.close();
    }
    ~ini_parser() {  }

    std::string trim(std::string s) {
        int n = s.size();
        // исключаем пробелы в началее строки
        int i = 0;
        while (s[i] == ' ' && i < n) {
            i++;
        }
        if (i != 0)
            s = s.substr(i, n - 1);

        // исключаем пробелы в конце строки
        n = s.size();
        i = n;
        while (s[i-1] == ' ' && i > 0) {
            i--;
        }
        if (i != n)
            s = s.substr(0, i);
        return s;

    }

    std::map<std::string, std::string> parser_in_map(const std::vector<std::string>& stroka, std::string section) {
        // номер строки
        int num_line = 0;
        bool coincidence = false;
        std::string line;
        std::map<std::string, std::string> v;

        while (num_line < stroka.size()) {
            line = stroka[num_line];
            //поиск начала названия секции
            if (line.size() != 0) {
                std::size_t position_l = line.find("[");
                if (position_l < line.length()) {
                    //поиск конца названия секции
                    std::size_t position_r = line.find("]");
                    if (position_r < line.length()) {
                        //проверяем совпадение названия секции
                        if (section == line.substr(position_l + 1, position_r - position_l - 1)) {
                            num_line++;
                            coincidence = true;
                            continue;
                        }
                        else {
                            coincidence = false;
                        }
                    }
                    else throw MyException("Синтаксическая ошибка", num_line);
                }
            }
            // если секция соответствует, считываем переменные
            if (coincidence) {
                std::string var = "";
                for (int i = 0; i < line.length(); i++) {
                    if (line[i] == ';') {
                        break;  // исключаем комментарии
                    }
                    var += line[i];
                    //  }
                }
                if (var != "") {
                    //поиск положения разделителя
                    int npos = var.find("=");
                    //проверка наличия знака =
                    if (npos < line.length()) {
                        //исключаем пробелы и сохраняем в карту
                        v[trim(var.substr(0, npos))] = trim(var.substr(npos + 1, var.length()));
                    }
                    else throw MyException("Синтаксическая ошибка", num_line);
                }
            }
            num_line++;
        }
        return v;
    }

    void parser_zaprosa(std::string s) {
        //поиск положения разделителя
        std::size_t npos = s.find(".");
        //получение подстроки
        this->_section = s.substr(0, npos);
        this->_var = s.substr(npos + 1, s.length());
    }


    template <class T>
    T get_value(const std::string name) {
        
        parser_zaprosa(name);      
        v = parser_in_map(this->stroka, this->_section);
                
        //проверка наличия переменной в секции
        auto search = v.find(this->_var);
        if (search == v.end()) {
            std::cout << "Такой переменной в ["<< this->_section << "] нет. Зато имеются следующие переменные : " << std::endl;
            if (v.size() > 0) {
                for (const auto& s : v)
                    std::cout << s.first << std::endl;
            }
            else std::cout << "Упс! Переменных в секции нет!" << std::endl;

        throw std::exception("Попробуйте ещё раз.");
        }

        //возврат значения переменной
        if (typeid(T) == typeid(int)) 
            return stoi(v[this->_var]);
        if (typeid(T) == typeid(double)) 
            return stod(v[this->_var]);
    }

    template<>
    std::string get_value(const std::string name) {
        
        parser_zaprosa(name);
        v = parser_in_map(this->stroka, this->_section);

        //проверка наличия переменной в секции
        auto search = v.find(this->_var);
        if (search == v.end()) {
            std::cout << "Такой переменной в [" << this->_section << "] нет. Зато имеются следующие переменные : " << std::endl;
            if (v.size() > 0) {
                for (const auto& s : v)
                    std::cout << s.first << std::endl;
            }
            else std::cout << "Упс! Переменных в секции нет!" << std::endl;

            throw std::exception("Попробуйте ещё раз.");
        }
    return v[this->_var];
    }
};


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    try {
        ini_parser parser("config.ini");

    //    auto value = parser.get_value<double>("Section1.var1");
    //    auto value = parser.get_value<int>("Section3.var1");
        auto value = parser.get_value<std::string>("Section1.var2");
    //    auto value = parser.get_value<int>("Section4.Mode2");

        std::cout << "Значение искомой переменной = " << value << std::endl;
    }
    catch (MyException &ex) {    
        std::cout << ex.what() << " в строке: " << ex.getNum_line() << std::endl;
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
    }
}