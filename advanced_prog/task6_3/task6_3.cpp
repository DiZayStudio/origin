#include <iostream>
#include "Windows.h"

class MissingElement : public std::exception {
public:
	const char* what() const override { return "Отсутствует элемент"; }
};

template <class T>
class my_vector {
public:
	int _size;
	T* _my_arr;
	int _current_ind;

public:
	my_vector() {
		_size = 1;
		_current_ind = 0;
		_my_arr = new T[_size];	
	}

	~my_vector() {
		delete[] _my_arr;
	}

	void push_back(T value) {
		if (_current_ind < _size) {
			_my_arr[_current_ind] = value;
			_current_ind++;
		}
		else {
			T* temp = new T[_size*2];

			for (int i = 0; i < _size; i++) {
				temp[i] = _my_arr[i];
			}
			_size *= 2;

			*_my_arr = *temp;

			std::cout << _my_arr << " - my_arr" << std::endl;
			std::cout << temp << " - temp" << std::endl;

			delete[] temp;

			_my_arr[_current_ind] = value;
			_current_ind++;
		}
	}

	T at(int n) {
		if (n < _current_ind && n >= 0) return _my_arr[n];
		else throw MissingElement();
	}

	int size() {
		return _current_ind;
	}
	 
	int capacity() {
		return _size - _current_ind;
	}


//	table(const table& t) = delete;
//	table& operator=(const table& t) = delete;

//	my_vector(const my_vector& v) = delete;
//	my_vector& operator=(const my_vector& v) = delete;
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		my_vector<int> V;
		V.push_back(10);
		V.push_back(20);
		V.push_back(30);

		std::cout << V.at(0) << std::endl;
		std::cout << V.at(1) << std::endl;
		std::cout << V.at(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
