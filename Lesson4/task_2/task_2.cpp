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
    Address() {
    }
    Address(std::string sity, std::string street, int house, int apartment) {
        this->sity = sity;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
    }

    std::string get_output_address() {
        return sity + " " + street + " " + std::to_string(house) + " " + std::to_string(apartment);
    }
    std::string get_sity() {
        return sity;
    }
    void get_data(std::string* sity, std::string* street, int* house, int* apartment) {
        *sity = this->sity;
        *street = this->street;
        *house = this->house;
        *apartment = this->apartment;
    }
    void set_data(std::string sity, std::string street, int house, int apartment) {
        this->sity = sity;
        this->street = street;
        this->house = house;
        this->apartment = apartment;
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

void write_file(Address* arr_address, int n) {
    std::ofstream fout("out.txt");
    if (fout.is_open()) {
        fout << n << std::endl;
        for (int i = n - 1; i >= 0; i--) {
            std::string out_text = arr_address[i].get_output_address();
            //   std::cout << out_text << std::endl;
            fout << out_text << std::endl;
        }
        fout.close();
        std::cout << "Файл out.txt записан" << std::endl;
    }
    else std::cout << "Не получилось открыть файл для записи" << std::endl;
}

void sort_address(Address* arr_address, int n) {

    std::string sity,sity_temp;
    std::string street,street_temp;
    int house,house_temp;
    int apartment,apartment_temp;

    bool swapped = false;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (arr_address[i].get_sity()[0] < arr_address[i + 1].get_sity()[0]) {
                arr_address[i].get_data(&sity, &street, &house, &apartment);
                arr_address[i + 1].get_data(&sity_temp, &street_temp, &house_temp, &apartment_temp);
                arr_address[i].set_data(sity_temp, street_temp, house_temp, apartment_temp);
                arr_address[i + 1].set_data(sity, street, house, apartment);
                swapped = true;
            }
        }
    } while (swapped);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n = 0;
    Address* arr_address = read_file("in.txt", &n);

    sort_address(arr_address, n);

    write_file(arr_address, n);

    delete[] arr_address;
}