#include <iostream>

template<class T>
class MyPointer
{
private:
	T* ptr;

public:
	MyPointer(T *ptr) {
		this->ptr = ptr;
	};
	~MyPointer() {
		delete ptr;
	};

	T& operator * () {
		return *ptr;
	}

	T* release() {
		return ptr;
	}

	MyPointer(const MyPointer& T) = delete;
	MyPointer& operator=(const MyPointer& T) = delete;


};


int main()
{
	setlocale(LC_ALL, "ru");

	MyPointer<int> pointer = new int(155);

	*pointer = 100;

	std::cout << &pointer << std::endl;
	std::cout << *pointer << std::endl;

	int* num = pointer.release();

	std::cout << *pointer << std::endl;
	std::cout << num << std::endl;
	std::cout << *num << std::endl;
}

