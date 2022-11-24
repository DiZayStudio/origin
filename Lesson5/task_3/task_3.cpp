#include <iostream>
#include <Windows.h>
#include <string>

class Figure {
protected:
    std::string name_;
    int sides_count_;

public:
    Figure() {
        sides_count_ = 0;
        name_ = "Фигура";
    };
    //   int get_sides_count() { return sides_count_; }
    //   std::string get_name() { return name_; }
    virtual void get_sides() {}
    virtual void get_angle() {}
    virtual void print_info() {
        std::cout << name_ << std::endl;
        std::cout << "Количество сторон: " << sides_count_ << std::endl;
    }
    virtual bool check() {
        if (sides_count_ == 0) return true;
        else return false;
    }
};

class Triangle : public Figure {
protected:
    int a_, b_, c_;
    int A_, B_, C_;

public:
    Triangle(int A, int B, int C, int a, int b, int c) {
        sides_count_ = 3;
        name_ = "Треугольник";
        this->A_ = A;
        this->B_ = B;
        this->C_ = C;
        this->a_ = a;
        this->b_ = b;
        this->c_ = c;
    }
    void get_sides() override {
        std::cout << "Стороны:";
        std::cout << " a=" << this->a_ << " b=" << this->b_ << " c=" << this->c_ << std::endl;
    }

    void get_angle() override {
        std::cout << "Углы:";
        std::cout << " A=" << this->A_ << " B=" << this->B_ << " C=" << this->C_ << std::endl;
    }
    void print_info() override {
        Figure::print_info();
    }
    bool check() override {
        if (sides_count_ == 3 && (A_ + B_ + C_ == 180)) return true;
        else return false;
    }
};

class Quadrangle : public Figure {
protected:
    int a_, b_, c_, d_;
    int A_, B_, C_, D_;

public:
    Quadrangle(int A, int B, int C, int D, int a, int b, int c, int d) {
        sides_count_ = 4;
        name_ = "Четырёхугольник";
        this->A_ = A;
        this->B_ = B;
        this->C_ = C;
        this->D_ = D;
        this->a_ = a;
        this->b_ = b;
        this->c_ = a;
        this->d_ = b;
    }
    void get_sides() override {
        std::cout << "Стороны:";
        std::cout << " a=" << this->a_ << " b=" << this->b_ << " c=" << this->c_ << " d=" << this->d_ << std::endl;
    }
    void get_angle() override {
        std::cout << "Углы:";
        std::cout << " A=" << this->A_ << " B=" << this->B_ << " C=" << this->C_ << " D=" << this->D_ << std::endl;
    }
    void print_info() override {
        Figure::print_info();
    }
    bool check() override {
        if (sides_count_ == 4 && (A_ + B_ + C_ + D_ == 360)) return true;
        else return false;
    }
};
//прямоугольный треугольник
class Right_triangle : public Triangle {
public:
    Right_triangle(int A, int B, int a, int b, int c) : Triangle(A, B, 90, a, b, c) {
        this->name_ = "Прямоугольный треугольник";
    }
    bool check() override {
        if (C_ == 90) return true;
        else return false;
    }
};

//равнобедренный треугольник
class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle(int A, int B, int a, int b) : Triangle(A, B, A, a, b, a) {
        this->name_ = "Равнобедренный треугольник";
    }
    bool check() override {
        if (a_ == c_ && A_ == C_) return true;
        else return false;
    }
};

//равносторонний треугольник
class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int a) : Triangle(60, 60, 60, a, a, a) {
        this->name_ = "Равносторонний треугольник";
    }
    bool check() override {
        if (a_ == b_ && b_ == c_ && A_ == B_ && B_ == C_) return true;
        else return false;
    }
};

//параллелограмм
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int A, int B, int a, int b) :Quadrangle(A, B, A, B, a, b, a, b) {
        this->name_ = "Параллелограмм";
    }
    bool check() override {
        if (a_ == c_ && b_ == d_ && A_ == C_ && B_ == D_ ) return true;
        else return false;
    }
};

//квадрат
class Square : public Parallelogram {
public:
    Square(int a) : Parallelogram(90, 90, a, a) {
        this->name_ = "Квадрат";
    }
    bool check() override {
        if (a_ == b_ && b_ == c_ && c_ == d_ && A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90) return true;
        else return false;
    }
};

//прямоугольник
class Rectangl : public Parallelogram {
public:
    Rectangl(int a, int b) :Parallelogram(90, 90, a, b) {
        this->name_ = "Парямоугольник";
    }
    bool check() override {
        if (a_ == c_ && b_ == d_ && A_ == 90 && B_ == 90 && C_ == 90 && D_ == 90) return true;
        else return false;
    }
};

//ромб
class Rhomb : public Parallelogram {
public:
    Rhomb(int A, int B, int a) :Parallelogram(A, B, a, a) {
        this->name_ = "Ромб";
    }
    bool check() override {
        if (a_ == c_ && b_ == d_ && A_ == C_ && B_ == D_) return true;
        else return false;
    }
};

void print_info(Figure* f) {
    std::string check;
    f->print_info();
    f->get_sides();   
    f->get_angle();
    if (f->check())
        check = "Правильная";
    else
        check = "Неправильная";
    std::cout << check << std::endl;
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure f0;
    Triangle f1(50, 60, 70, 10, 20, 30);
    Right_triangle f2(50, 60, 10, 20, 30);
    Isosceles_triangle f3(50, 60, 10, 20);
    Equilateral_triangle f4(30);

    Quadrangle f5(50, 60, 70, 80, 10, 20, 30, 40);
    Rectangl f6(10, 20);
    Square f7(20);
    Parallelogram f8(30, 40, 20, 30);
    Rhomb f9(30, 40, 30);

    print_info(&f0);
    print_info(&f1);
    print_info(&f2);
    print_info(&f3);
    print_info(&f4);
    print_info(&f5);
    print_info(&f6);
    print_info(&f7);
    print_info(&f8);
    print_info(&f9);
}