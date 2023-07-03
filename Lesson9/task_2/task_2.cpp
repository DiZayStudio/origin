#include <iostream>
#include <Windows.>h
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	bool operator == (Fraction num) {
		if (this->numerator_ * num.denominator_ == num.numerator_ * this->denominator_) return true;
		else return false;
	}
	bool operator != (Fraction num) {
		return !(*this == num);
	}
	bool operator < (Fraction num) {
		if (this->numerator_ * num.denominator_ < num.numerator_ * this->denominator_) return true;
		else return false;
	}
	bool operator > (Fraction num) {
		return (num < *this);
	}
	bool operator <= (Fraction num) {
		return !(*this > num);
	}
	bool operator >= (Fraction num) {
		return !(*this < num);
	}

	std::string get_str() {
		return std::to_string(this->numerator_) + "/" + std::to_string(this->denominator_);
	}

	Fraction operator + (Fraction num) {
		return Fraction(numerator_ * num.denominator_ + num.numerator_ * denominator_, num.denominator_* denominator_);
	}
	Fraction operator - (Fraction num) {
		return Fraction(numerator_ * num.denominator_ - num.numerator_ * denominator_, num.denominator_ * denominator_);
	}
	Fraction operator * (Fraction num) {
		return Fraction(numerator_ * num.numerator_, denominator_ * num.denominator_);
	}
	Fraction operator / (Fraction num) {
		return Fraction(numerator_ * num.denominator_, denominator_ * num.numerator_);
	}
	Fraction& operator ++ () {
		numerator_ = numerator_ + denominator_;
		return *this;
	}
	Fraction& operator ++ (int) {
		Fraction temp{ *this };
		++(*this);
		return temp;
	}
	Fraction& operator -- () {
		numerator_ = numerator_ - denominator_;
		return *this;
	}
	Fraction& operator -- (int) {
		Fraction temp{ *this };
		--(*this);
		return temp;
	}

	Fraction& reduction() {
		int x = numerator_;
		int y = denominator_;

		do {
			if (x > y) x = x % y;
			else y = y % x;
		} while ((x != 0) && (y != 0));
		int nod = x + y;
		numerator_ = numerator_ / nod;
		denominator_ = denominator_ / nod;
		return *this;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int numerator;
	int denominator;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator;

	std::cout << "Введите знаменатель дроби 1 : ";
	std::cin >> denominator;

	Fraction f1(numerator, denominator);

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator;

	std::cout << "Введите знаменатель дроби 2 : ";
	std::cin >> denominator;

	Fraction f2(numerator, denominator);

	std::cout << f1.get_str() << " + " << f2.get_str() << " = " << (f1 + f2).get_str() << '\n';
	std::cout << f1.get_str() << " - " << f2.get_str() << " = " << (f1 - f2).get_str() << '\n';
	std::cout << f1.get_str() << " * " << f2.get_str() << " = " << (f1 * f2).reduction().get_str() << '\n';
	std::cout << f1.get_str() << " / " << f2.get_str() << " = " << (f1 / f2).reduction().get_str() << '\n';
	
	std::cout << "++" << f1.get_str() << " * " << f2.get_str();
	std::cout << " = " << (++f1 * f2).reduction().get_str() << '\n';
	std::cout << "Значение дроби 1 = " << f1.get_str() << '\n';
	
	std::cout << f1.get_str() << "--" << " * " << f2.get_str();
	std::cout << " = " << (f1-- * f2).reduction().get_str() << '\n';
	std::cout << "Значение дроби 1 = " << f1.get_str() << '\n';

	return 0;
}