#include <iostream>

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
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, 11);
//	Fraction f2(8, 6);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}