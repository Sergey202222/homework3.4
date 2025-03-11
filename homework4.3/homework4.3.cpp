#include <iostream>

class Figure
{
protected:
    int side_counts;
public:
    Figure(int side_counts)
    {
        this->side_counts = side_counts;
    }
    virtual bool check()
    {
        return side_counts == 0;
    }
    virtual void print_info()
    {
        if (check())
        {
            std::cout << "Правильная\n";
        }
        else
        {
            std::cout << "Неправильная!\n";
        }
        std::cout << "Количество сторон: " << side_counts << "\n\n";
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
    Triangle(int side_counts, int a, int b, int c, int A, int B, int C) : Figure(side_counts)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
    }
    virtual bool check() override
    {
        return side_counts == 3 && A + B + C == 180;
    }
    void print_info() override
    {
        if (check())
        {
            std::cout << "Правильная\n";
        }
        else
        {
            std::cout << "Неправильная!\n";
        }
        std::cout << "Количество сторон: " << side_counts << '\n';
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }

};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int side_counts, int a, int b, int c, int A, int B, int C) : Triangle(side_counts, a, b, c, A, B, C)
    {}
    bool check() override
    {
        return Triangle::check() && C == 90;
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int side_counts, int a, int b, int c, int A, int B, int C) : Triangle(side_counts, a, b, c, A, B, C)
    {}
    bool check() override
    {
        return Triangle::check() && a == c && A == C;
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int side_counts, int a, int b, int c, int A, int B, int C) : Triangle(side_counts, a, b, c, A, B, C)
    {}
    bool check() override
    {
        return Triangle::check() && a == c && a == b && A == 60 && B == 60 && C == 60;
    }
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
    Quadrangle(int side_counts, int a, int b, int c, int d, int A, int B, int C, int D) : Figure(side_counts)
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
    virtual bool check() override
    {
        return side_counts == 4 && A + B + C + D == 360;
    }
    void print_info() override
    {
        if (check())
        {
            std::cout << "Правильная\n";
        }
        else
        {
            std::cout << "Неправильная!\n";
        }
        std::cout << "Количество сторон: " << side_counts << '\n';
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c <<
            " d=" << d << '\n';
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" <<
            D << "\n\n";
    }
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int side_counts, int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(side_counts, a, b, c, d, A, B, C, D)
    {}
    virtual bool check() override
    {
        return Quadrangle::check() && a == c && b == d && A == C && B == D;
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int side_counts, int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(side_counts, a, b, c, d, A, B, C, D)
    {}
    virtual bool check() override
    {
        return Parallelogram::check() && A == 90, B == 90, C == 90, D == 90;
    }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int side_counts, int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(side_counts, a, b, c, d, A, B, C, D)
    {}
    virtual bool check() override
    {
        return Parallelogram::check() && a == b;
    }
};

class Square : public Rectangle
{
public:
    Square(int side_counts, int a, int b, int c, int d, int A, int B, int C, int D) : Rectangle(side_counts, a, b, c, d, A, B, C, D)
    {}
    bool check() override
    {
        return Rectangle::check() && a == b;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Figure figure(0);
    Triangle triangle(3, 10, 20, 30, 50, 60, 70);
    RightTriangle _rightTriangle1(3, 10, 20, 30, 50, 60, 90);
    RightTriangle _rightTriangle2(3, 10, 20, 30, 50, 40, 90);
    Triangle* rightTriangle1{ &_rightTriangle1 };
    Triangle* rightTriangle2{ &_rightTriangle2 };
    IsoscelesTriangle isoscelesTriangle1(3, 10, 20, 10, 50, 60, 50);
    Triangle* isoscelesTriangle{ &isoscelesTriangle1 };
    EquilateralTriangle equilateralTriangle1(3, 30, 30, 30, 60, 60, 60);
    Triangle* equilateralTriangle{ &equilateralTriangle1 };
    Quadrangle quadrangle(4, 10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle1(4, 10, 20, 10, 20, 90, 90, 90, 90);
    Quadrangle* rectangle{ &rectangle1 };
    Square square1(4, 20, 20, 20, 20, 90, 90, 90, 90);
    Quadrangle* square{ &square1};
    Parallelogram parallelogram1(4, 20, 30, 20, 30, 30, 40, 30, 40);
    Quadrangle* parallelogram{ &parallelogram1};
    Rhombus rhombus1(4, 30, 30, 30, 30, 30, 40, 30, 40);
    Quadrangle* rhombus{ &rhombus1 };

    std::cout << "Фигура:\n";
    figure.print_info();
    std::cout << "Треугольник:\n";
    triangle.print_info();
    std::cout << "Прямоугольный треугольник:\n";
    rightTriangle1->print_info();
    std::cout << "Прямоугольный треугольник:\n";
    rightTriangle2->print_info();
    std::cout << "Равнобедренный треугольник:\n";
    isoscelesTriangle->print_info();
    std::cout << "Равносторонний треугольник::\n";
    equilateralTriangle->print_info();
    std::cout << "Четырёхугольник:\n";
    quadrangle.print_info();
    std::cout << "Прямоугольник:\n";
    rectangle->print_info();
    std::cout << "Квадрат:\n";
    square->print_info();
    std::cout << "Параллелограмм:\n";
    parallelogram->print_info();
    std::cout << "Ромб:\n";
    rhombus->print_info();
    return EXIT_SUCCESS;
}