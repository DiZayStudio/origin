#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

class Address {
private:
    std::string sity;
    std::string street;
    int house;
    int apartment;

public:
    Address(){}
    Address(std::string sity, std::string street, int house, int apartment) {
        this->sity = sity;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }

    std::string get_output_address() {
        return sity + " " + street + " " + std::to_string(house) + " " + std::to_string(apartment);
    }
};

Address* read_file(std::string name, int* n) {
    std::ifstream file(name);

    if (file.is_open()) {
        
        file >> *n;

        std::string sity;
        std::string street;
        int house;
        int apartment;

        Address* arr_address = new Address[*n];

        for (int i = 0; i < *n; i++) {
            file >> sity;
            file >> street;
            file >> house;
            file >> apartment;

            arr_address[i] = Address(sity, street, house, apartment);
        }
        std::string s;
        file.close();
        std::cout << "Файл " << name << " прочитан" << std::endl;
        return arr_address;
    }
    else std::cout << "Не получилось открыть файл " << name << std::endl;
}

void write_file(Address* arr_address,int* n) {
    std::ofstream fout("out.txt");
    if (fout.is_open()) {
        fout << *n << std::endl;
        for (int i = *n - 1; i >= 0; i--) {
            std::string out_text = arr_address[i].get_output_address();
         //   std::cout << out_text << std::endl;
            fout << out_text << std::endl;
        }
        fout.close();
        std::cout << "Файл out.txt записан" << std::endl;
    } else std::cout << "Не получилось открыть файл для записи" << std::endl;
}

int main()
{
   SetConsoleCP(1251);
   SetConsoleOutputCP(1251);

   int n;
   Address* arr_address = read_file("in.txt", &n);
   
   write_file(arr_address, &n);

   delete[] arr_address;
}