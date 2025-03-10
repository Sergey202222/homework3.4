#include <iostream>

class Figure
{
protected:
    int sides_count;
    std::string name_figure;
public:
    Figure()
    {
        sides_count = 0;
        name_figure = "Фигура";
    }
    int get_sides_count()
    {
        return sides_count;
    }
    std::string get_name_figure()
    {
        return name_figure;
    }
};

class Triangle : public Figure
{
public:
    Triangle()
    {
        sides_count = 3;
        name_figure = "Треугольник";
    }
};

class Quadrangle : public Figure
{
public:
    Quadrangle()
    {
        sides_count = 4;
        name_figure = "Четырёхугольник";
    }
};

int main()
{
    setlocale(LC_ALL, "rus");
    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;

    std::cout << "Количество сторон:\n";
    std::cout << figure.get_name_figure() << ": " << figure.get_sides_count() << '\n';
    std::cout << triangle.get_name_figure() << ": " << triangle.get_sides_count() << '\n';
    std::cout << quadrangle.get_name_figure() << ": " << quadrangle.get_sides_count();
    return EXIT_SUCCESS;
}