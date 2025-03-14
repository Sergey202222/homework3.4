#include <iostream>

class Figure
{
protected:
    int side_counts;
public:
    Figure(int side_counts) : side_counts(side_counts)
    {}
    virtual int get_a()
    {
        return 0;
    }
    virtual int get_b()
    {
        return 0;
    }
    virtual int get_c()
    {
        return 0;
    }
    virtual int get_d()
    {
        return 0;
    }

    virtual int get_A()
    {
        return 0;
    }
    virtual int get_B()
    {
        return 0;
    }
    virtual int get_C()
    {
        return 0;
    }
    virtual int get_D()
    {
        return 0;
    }
};

class Triangle : public Figure
{
protected:
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
public:
    Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    int get_a() override
    {
        return a;
    }
    int get_b() override
    {
        return b;
    }
    int get_c() override
    {
        return c;
    }
    int get_A() override
    {
        return A;
    }
    int get_B() override
    {
        return B;
    }
    int get_C() override
    {
        return C;
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
    {}
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {}
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {}
};

class Quadrangle : public Figure
{
protected:
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
    }
    int get_a() override
    {
        return a;
    }
    int get_b() override
    {
        return b;
    }
    int get_c() override
    {
        return c;
    }
    int get_d() override
    {
        return d;
    }
    int get_A() override
    {
        return A;
    }
    int get_B() override
    {
        return B;
    }
    int get_C() override
    {
        return C;
    }
    int get_D() override
    {
        return D;
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B)
    {}
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int a, int b) : Parallelogram(a, b, 90, 90)
    {}
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B)
    {}
};

class Square : public Rhombus
{
public:
    Square(int a) : Rhombus(a, 90, 90)
    {}
};

void print_info(Figure* base)
{
    std::cout << "Стороны: a=" << base->get_a() << " b=" << base->get_b() << " c=" << base->get_c();
    if (base->get_d() != 0) std::cout << " d=" << base->get_d() << '\n';
    else std::cout << '\n';
    std::cout << "Углы: A=" << base->get_A() << " B=" << base->get_B() << " C=" << base->get_C();
    if (base->get_D() != 0) std::cout << " D=" << base->get_D() << "\n\n";
    else std::cout << "\n\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60); 
    EquilateralTriangle equilateralTriangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    std::cout << "Треугольник:\n";
    print_info(&triangle);
    std::cout << "Прямоугольный треугольник:\n";
    print_info(&rightTriangle);
    std::cout << "Равнобедренный треугольник:\n";
    print_info(&isoscelesTriangle);
    std::cout << "Равносторонний треугольник::\n";
    print_info(&equilateralTriangle);
    std::cout << "Четырёхугольник:\n";
    print_info(&quadrangle);
    std::cout << "Прямоугольник:\n";
    print_info(&rectangle);
    std::cout << "Квадрат:\n";
    print_info(&square);
    std::cout << "Параллелограмм:\n";
    print_info(&parallelogram);
    std::cout << "Ромб:\n";
    print_info(&rhombus);
    return EXIT_SUCCESS;
}