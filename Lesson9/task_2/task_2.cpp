#include <iostream>
#include <Windows.h>
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
		if (this->numerator_ * num.denominator_ != num.numerator_ * this->denominator_) return true;
		else return false;
	}
	bool operator < (Fraction num) {
		if (this->numerator_ * num.denominator_ < num.numerator_ * this->denominator_) return true;
		else return false;
	}
	bool operator > (Fraction num) {
		if (this->numerator_ * num.denominator_ > num.numerator_ * this->denominator_) return true;
		else return false;
	}
	bool operator <= (Fraction num) {
		if (this->numerator_ * num.denominator_ <= num.numerator_ * this->denominator_) return true;
		else return false;
	}
	bool operator >= (Fraction num) {
		if (this->numerator_ * num.denominator_ >= num.numerator_ * this->denominator_) return true;
		else return false;
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

		if (numerator_ % 2 == 0 && denominator_ % 2 == 0 && numerator_ > 1 && denominator_ > 1) {
//			std::cout << "Делится на 2" << std::endl;
			do {
				numerator_ = numerator_ / 2;
				denominator_ = denominator_ / 2;
			} while (numerator_ % 2 == 0 && denominator_ % 2 == 0 && numerator_ > 1 && denominator_ > 1);
		}
		else if (numerator_ % 5 == 0 && denominator_ % 5 == 0 && numerator_ > 4 && denominator_ > 4) {
//			std::cout << "Делится на 5" << std::endl;
			do {
				numerator_ = numerator_ / 5;
				denominator_ = denominator_ / 5;
			} while (numerator_ % 5 == 0 && denominator_ % 5 == 0 && numerator_ > 4 && denominator_ > 4);
		}
		else if ((numerator_ % 10 + numerator_/10 % 10 ) % 3 == 0 && (denominator_ % 10 + denominator_ / 10 % 10) % 3 == 0 &&
			numerator_ > 2 && denominator_ > 2){
//			std::cout << "Делится на 3" << std::endl;
			do {
				numerator_ = numerator_ / 3;
				denominator_ = denominator_ / 3;
			} while ((numerator_ % 10 + numerator_ / 10 % 10) % 3 == 0 && (denominator_ % 10 + denominator_ / 10 % 10) % 3 == 0 &&
				numerator_ > 2 && denominator_ > 2);


		}
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

//	f2 = f1.reduction();

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