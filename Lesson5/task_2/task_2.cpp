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
    int get_sides_count() { return sides_count_; }
    std::string get_name() { return name_; }
    virtual void get_sides() {};
    virtual void get_angle() {};
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
        std::cout << " a=" << this->a_ << " b=" << this->b_ << " c=" << this->c_ <<std::endl;
    }

    void get_angle() override {
        std::cout << " A=" << this->A_ << " B=" << this->B_ << " C=" << this->C_ << std::endl;
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
        std::cout << " a=" << this->a_ << " b=" << this->b_ << " c=" << this->c_ << " d=" << this->d_ << std::endl;
    }
    void get_angle() override {
        std::cout << " A=" << this->A_ << " B=" << this->B_ << " C=" << this->C_ << " D=" << this->D_ << std::endl;
    }
};
//прямоугольный треугольник
class Right_triangle : public Triangle {
public:
    Right_triangle(int A, int B, int a, int b, int c) : Triangle(A, B, 90, a, b, c) {
        this->name_ = "Прямоугольный треугольник";
    }
};

//равнобедренный треугольник
class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle(int A, int B, int a, int b) : Triangle(A, B, A, a, b, a) {
        this->name_ = "Равнобедренный треугольник";
    }
};

//равносторонний треугольник
class Equilateral_triangle : public Triangle {
public:
    Equilateral_triangle(int a) : Triangle(60, 60, 60, a, a, a) {
        this->name_ = "Равносторонний треугольник";
    }
};

//параллелограмм
class Parallelogram : public Quadrangle {
public:
    Parallelogram(int A, int B, int a, int b) :Quadrangle(A, B, A, B, a, b, a, b) {
        this->name_ = "Параллелограмм";
    }
};

//квадрат
class Square : public Parallelogram {
public:
    Square(int a) : Parallelogram(90, 90, a, a) {
        this->name_ = "Квадрат";
    }
};

//прямоугольник
class Rectangl : public Parallelogram {
public:
    Rectangl(int a, int b) :Parallelogram(90, 90, a, b) {
        this->name_ = "Парямоугольник";
    }
};

//ромб
class Rhomb : public Parallelogram {
public:
    Rhomb(int A, int B, int a) :Parallelogram(A, B, a, a) {
        this->name_ = "Ромб";
    }
};

void print_info(Figure* f) {
    std::cout << f->get_name() << ":" << std::endl;
    
    std::cout << "Стороны:";
    f->get_sides();
    std::cout << "Углы:";
    f->get_angle();
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Triangle f1(50, 60, 70, 10, 20, 30);
    Right_triangle f2(50, 60, 10, 20, 30);
    Isosceles_triangle f3(50, 60, 10, 20);
    Equilateral_triangle f4(30);

    Quadrangle f5(50, 60, 70, 80, 10, 20, 30, 40);
    Rectangl f6(10, 20);
    Square f7(20);
    Parallelogram f8(30, 40, 20, 30);
    Rhomb f9(30, 40, 30);

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