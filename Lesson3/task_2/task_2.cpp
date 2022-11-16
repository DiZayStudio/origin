#include <iostream>
#include <Windows.h>

class Counter {
private:
    int count;

public:
    Counter() {
        this->count = 1;
    }
    Counter(int count) {
        this->count = count;
    }

    void inc() {
        count++;
    }
    void dec() {
        count--;
    }
    int get_count() {
       return count;
    }
};

void input_command(Counter& c) {
    do {
        char command = ' ';
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        // Условие двойное для рус и анг языка
        if (command == 'х' || command == 'x')
            break;
        else if (command == '+')
            c.inc();
        else if (command == '-')
            c.dec();
        else if (command == '=') {
            std::cout << c.get_count() << std::endl;
        }
    } while (true);
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input;
    int n = 0;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> input;
    if (input == "да")
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> n;
       Counter counter(n);
       input_command(counter);
    }
    else {
        Counter counter;
        input_command(counter);
    }


        

       
    
}

