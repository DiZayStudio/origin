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

void input_command(Counter& count) {
    do {
        char command = ' ';
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        // Условие двойное для рус и анг языка
        if (command == 'х' || command == 'x')
            break;
        else if (command == '+')
            count.inc();
        else if (command == '-')
            count.dec();
        else if (command == '=') {
            std::cout << count.get_count() << std::endl;
        }
    } while (true);
}

 Counter setup() {
    std::string input;
    int n = 0;
    
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> input;
    if (input == "да")
    {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> n;
        Counter counter(n);
        return counter;
    }
    else {
        Counter counter;
        return counter;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Counter count = setup();

    input_command(count);
}

