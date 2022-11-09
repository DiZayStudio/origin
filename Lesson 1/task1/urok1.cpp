// urok1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include <iostream>

void shift_left(int* arr, int n) {
    int temp = arr[0];

    for (int i = 1; i <= n-1; i++) {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

void shift_right(int* arr, int n) {
    int temp = arr[n-1];

    for (int i = n-1; i >= 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main()
{
    setlocale(LC_ALL, "Russian");   

    int n,m;

    std::ifstream file("in.txt");

    if (file.is_open()) {
        std::string s;
        while (!(file.eof()))
        {
            
            file >> n;

            int* arr_in1 = new int[n];

            for (int i = 0; i < n; i++) {
                file >> arr_in1[i];
            }

            file >> m;

            int* arr_in2 = new int[m];

            for (int i = 0; i < m; i++) {
                file >> arr_in2[i];
            }

            shift_left(arr_in1, n);
            shift_right(arr_in2, m);

            std::ofstream fout("out.txt");

            if (fout.is_open()) {
                fout << m << std::endl;

                for (int i = 0; i < m; i++) {
                    fout << arr_in2[i] << " ";
                }
                fout << std::endl;
                fout << n << std::endl;

                for (int i = 0; i < n; i++) {
                    fout << arr_in1[i] << " ";
                }
                fout.close();
            }
            else {
                std::cout << "Не получилось открыть файл!" << std::endl;
            }
            delete[] arr_in1;
            delete[] arr_in2;
        }
    }
    else {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }
    file.close();
}

