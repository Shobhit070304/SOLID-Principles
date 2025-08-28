#include <iostream>

using namespace std;

class Shape
{
public:
    virtual int getArea() const = 0;
};

class Rectangle : public Shape
{
public:
    int width;
    int height;

    Rectangle(int w, int h)
    {
        width = w;
        height = h;
    }

    int getArea() const override
    {
        return width * height;
    }
};

class Square : public Shape
{
    int side;

public:
    Square(int s)
    {
        side = s;
    }

    int getArea() const override
    {
        return side * side;
    }
};

void printArea(Shape &shape)
{
    cout << "Area: " << shape.getArea() << endl;
}
int main()
{
    Rectangle rect(2, 4);
    printArea(rect);

    Square square(3);
    printArea(square);

    return 0;
}
