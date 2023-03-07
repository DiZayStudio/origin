#include <iostream>
#include "Windows.h"

template <class T>
class table {
private:
    T rows;
    T cols;
    T** arr;

public:
    table(T row, T col)
    {
        this->rows = row;
        this->cols = col;
        arr = new T * [this->rows];
        for (int i = 0; i < this->rows; i++)
        {
            arr[i] = new T[this->cols];
        }
    }

    ~table()
    {
        for (int i = 0; i < this->rows; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }

    T* operator[] (T index) {
        return arr[index];
    }

    const T* operator[] (T index) const {
        return arr[index];
    }

    const int Size() {
        return this->rows * this->cols;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    std::cout << "Размер таблицы: " << test.Size() << std::endl;
}
