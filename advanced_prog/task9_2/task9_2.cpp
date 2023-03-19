#include <iostream>

class big_integer {
private:
    std::string num_;

public:
    big_integer() {
        this->num_ = "0";
    }

    big_integer(std::string num) {
        this->num_ = num;
    }

    big_integer operator + (big_integer) {

        return *this;
    }
    big_integer operator * (int x) {

        return *this;
    }

    big_integer operator->() const { 
        return big_integer;
    }
};


int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result; // 193099
}
