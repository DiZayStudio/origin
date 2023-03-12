#include <iostream>
#include "Windows.h"

class DestinationObjects : public std::exception {
public:
    const char* what() const override { return "Присвоение объекта самому себе"; }
};

template <class T>
class table {
private:
    int rows;
    int cols;
    T** arr;

public:
    table(int row, int col)
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

 //   table(const table& t) = delete;
 //   table& operator=(const table& t) = delete;

    table& operator = (const table& t) {
        if (this != &t) {
            for (int i = 0; i < rows; i++) {
                delete[] arr[i];
            }
            delete[] arr;

            rows = t.rows;
            cols = t.cols;

            arr = new T * [t.rows];
            for (int i = 0; i < rows; i++) {
                arr[i] = new T[cols];
            }

            for (int i = 0; i < t.rows; i++) {
                for (int j = 0; j < t.rows; j++)
                    this->arr[i][j] = t.arr[i][j];
            }
            return *this;
        }
    }

    table (const table& t) {
            for (int i = 0; i < rows; i++) {
                delete[] arr[i];
            }
            delete[] arr;

            rows = t.rows;
            cols = t.cols;

            arr = new T * [t.rows];
            for (int i = 0; i < rows; i++) {
                arr[i] = new T[cols];
            }

            for (int i = 0; i < t.rows; i++) {
                for (int j = 0; j < t.rows; j++)
                    this->arr[i][j] = t.arr[i][j];
            }
     }

};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto test = table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0] << std::endl;

    test = test;
    auto test2 = test;

    std::cout << "Размер таблицы: " << test.Size() << std::endl;
}
