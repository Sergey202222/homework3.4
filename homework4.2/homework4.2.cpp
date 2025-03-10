#include <iostream>

class Triangle
{
protected:
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
public:
    Triangle(int a, int b, int c, int A, int B, int C)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    int get_a()
    {
        return a;
    }
    int get_b()
    {
        return b;
    }
    int get_c()
    {
        return c;
    }
    int get_A()
    {
        return A;
    }
    int get_B()
    {
        return B;
    }
    int get_C()
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

class Quadrangle
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
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
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
    int get_a()
    {
        return a;
    }
    int get_b()
    {
        return b;
    }
    int get_c()
    {
        return c;
    }
    int get_d()
    {
        return d;
    }
    int get_A()
    {
        return A;
    }
    int get_B()
    {
        return B;
    }
    int get_C()
    {
        return C;
    }
    int get_D()
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

void print_info(Triangle& triangle)
{
    std::cout << "Стороны: a=" << triangle.get_a() << " b=" << triangle.get_b() << " c=" << triangle.get_c() << '\n';
    std::cout << "Углы: A=" << triangle.get_A() << " B=" << triangle.get_B() << " C=" << triangle.get_C() << "\n\n";
}

void print_info(Quadrangle& quadrangle)
{
    std::cout << "Стороны: a=" << quadrangle.get_a() << " b=" << quadrangle.get_b() << " c=" << quadrangle.get_c() << 
    " d=" << quadrangle.get_d() << '\n';
    std::cout << "Углы: A=" << quadrangle.get_A() << " B=" << quadrangle.get_B() << " C=" << quadrangle.get_C() << " D=" <<
    quadrangle.get_D() << "\n\n";
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
    print_info(triangle);
    std::cout << "Прямоугольный треугольник:\n";
    print_info(rightTriangle);
    std::cout << "Равнобедренный треугольник:\n";
    print_info(isoscelesTriangle);
    std::cout << "Равносторонний треугольник::\n";
    print_info(equilateralTriangle);
    std::cout << "Четырёхугольник:\n";
    print_info(quadrangle);
    std::cout << "Прямоугольник:\n";
    print_info(rectangle);
    std::cout << "Квадрат:\n";
    print_info(square);
    std::cout << "Параллелограмм:\n";
    print_info(parallelogram);
    std::cout << "Ромб:\n";
    print_info(rhombus);
    return EXIT_SUCCESS;
}