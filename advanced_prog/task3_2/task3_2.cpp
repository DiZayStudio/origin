#include <iostream>
#include "Windows.h"

class ExceededSize : public std::exception {
public:
	const char* what() const override { return "Превышен размер массива"; }
};
class MissingElement : public std::exception {
public:
	const char* what() const override { return "Отсутствует элемент"; }
};
class DestinationObjects : public std::exception {
public:
	const char* what() const override { return "Присвоение объекта самому себе"; }
};


class smart_array {
private:
	int size;
	int* int_arr;
	int curent_ind = 0;

public:
	smart_array(int size) {
		this->size = size;
		int_arr = new int[size] {};
	}

	smart_array(const smart_array& other) {
			this->int_arr = new int[other.size];

			for (int i = 0; i < other.size; i++) {
				this->int_arr[i] = other.int_arr[i];
			}
			this->curent_ind = other.curent_ind;
			this->size = other.size;
	}

	~smart_array() {
		if (int_arr != nullptr) {
			delete[] int_arr;
		}
	}

	void add_element(int x) {
		if (curent_ind < size) {
			int_arr[curent_ind] = x;
			curent_ind++;
		}
		else throw ExceededSize();
	}
	int get_size() {
		return size;
	}

	int get_element(int n) {
		if (n < curent_ind && n >= 0) return int_arr[n];
		else throw MissingElement();
	}

	smart_array& operator = (const smart_array& other) {
		if (this != &other) {

			this->size = other.size;

			delete[] this->int_arr;

			this->int_arr = new int[other.size];

			for (int i = 0; i < other.size; i++) {
				this->int_arr[i] = other.int_arr[i];
			}
			return *this;
		} else throw DestinationObjects();
	}



};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);
		
		arr = new_array;

		smart_array arr2(arr);

		std::cout << arr.get_element(1) << std::endl;
		std::cout << arr2.get_element(1) << std::endl;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}
