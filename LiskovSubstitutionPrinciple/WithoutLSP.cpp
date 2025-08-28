#include <iostream>

using namespace std;

class Rectangle
{
public:
    int width;
    int height;

    virtual void setWidth(int w)
    {
        width = w;
    }

    virtual void setHeight(int h)
    {
        height = h;
    }

    int getArea() const
    {
        return width * height;
    }
};

class Square : public Rectangle
{
public:
    void setWidth(int w)
    {
        width = w;
        height = w;
    }

    void setHeight(int h)
    {
        width = h;
        height = h;
    }
};

void printArea(Rectangle &rect)
{
    rect.setWidth(5);
    rect.setHeight(10);
    cout << "Area: " << rect.getArea() << endl;
}
int main()
{
    Rectangle rect;
    printArea(rect);

    Square square;
    printArea(square);

    return 0;
}