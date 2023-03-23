#include <iostream>
#include <string>

class big_integer {
private:
    std::string num_;

public:
    big_integer() {
        this->num_ = "";
    }

    big_integer(std::string num) {
        this->num_ = num;
    }

    big_integer operator + (big_integer other) {
        
        int n1 = this->length();
        int n2 = other.length();
        int n = 0;
        std::string num1 = this->num_;
        std::string num2 = other.num_;
        
        //выравнивание длины чисел
        if (n1 < n2) {
            for(int i = 0; i < n2 - n1 ; i++)
                num1 = "0" + num1;
            n = n2;
        }
        else {
            for (int i = 0; i < n1 - n2; i++)
                num2 = "0" + num2;
            n = n1;
        }
    
        int sum = 0;
        int perenos = 0;
        std::string res = "";
        for (int i = n-1; i >= 0; i--) {
            sum = num1[i] - '0' + num2[i] - '0' + perenos;
            if (sum / 10 != 0) {
                sum = sum % 10;
                perenos = 1;
            }
            else perenos = 0;
            res = static_cast<char>(sum + '0') + res;
        }

        if (perenos == 1) res = "1" + res;
        
        this->num_ = res;
        return *this;
    }

    big_integer operator * (int x) {
        std::string num1 = this->num_;
        std::string num2 = std::to_string(x);
        int n1 = num1.length();
        int n2 = num2.length();
        big_integer res;
        big_integer temp;
        
        int mul = 0;
        int perenos = 0;
        int shift = 0;
        for (int i = n2 - 1; i >= 0; i--) {
            perenos = 0;
            for (int j = n1 - 1; j >= 0; j--) {
                mul = (num1[j] - '0') * (num2[i] - '0') + perenos;
                perenos = mul / 10;
                    mul = mul % 10;
                    
                res.num_ = static_cast<char>(mul + '0') + res.num_;
            }
            if (perenos != 0) res.num_ = static_cast<char>(perenos + '0') + res.num_;

            for (int i2 = 0; i2 < shift; i2++) res.num_ =  res.num_ + "0";

            shift++;
             temp = temp + res;
            res.num_ = "";
        }
        *this = temp;
        return *this;
    }

    int length() {
        return this->num_.length();
    }

    // конструктор перемещения
    big_integer(const big_integer& other) {
        if (this != &other) 
            this->num_ = other.num_;
    }

    big_integer(big_integer& other) {
        this->num_ = other.num_;
    }

    // оператор перемещающего присваивания
    big_integer& operator = (big_integer& other) noexcept
    {
        if (this != &other) 
            std::swap(this->num_, other.num_);
        return *this; 
    }

    big_integer& operator = (const big_integer& other) {
        if (this != &other) {
            this->num_ = other.num_;
        }
        return *this;
    }

    friend std::ostream& operator << (std::ostream &temp, const big_integer& other) {
        temp << other.num_;
        return temp;
    }
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
 
    auto result = number1 + number2;
    std::cout << result << std::endl;// 193099

    auto result2 = number2 * 269;
    std::cout << result2; //21122956
}
