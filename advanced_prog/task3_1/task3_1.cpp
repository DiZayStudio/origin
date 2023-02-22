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

class smart_array {
private:
	int size;
	int* int_arr;
	int curent_ind = 0;

public:
	smart_array(int size) {
		this->size = size;
		int_arr = new int[size];
	}
	
	~smart_array() {
		delete[] int_arr;
	}

	void add_element(int x) {
		if (curent_ind < size) {
			int_arr[curent_ind] = x;
			curent_ind++;
		}
		else throw ExceededSize();	
	}

	int get_element(int n) {
		if(n < size) return int_arr[n];
		else throw MissingElement();
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
		arr.add_element(14);
		arr.add_element(15);

	//	arr.add_element(15);

		std::cout << arr.get_element(0) << std::endl;
		std::cout << arr.get_element(1) << std::endl;

		std::cout << arr.get_element(5) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}
