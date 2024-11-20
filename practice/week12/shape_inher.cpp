#include <iostream>
using namespace std;

class Shape
{
    int x, y;
public:
    Shape()
    {
        cout << "Shape 생성자 ()" << endl;
    }
    Shape(int x_loc, int y_loc): x{x_loc}, y{y_loc}
    {
        cout << "Shape 생성자 (x_loc, y_loc)" << endl;
    }  
    ~Shape()
    {
        cout << "Shape 소멸자 ()" << endl;
    }
};

class Rectangle : public Shape
{
    int width, height;
public:
    Rectangle(int x, int y, int w, int h) : Shape(x, y)
    {
        width = w;
        height = h;
        cout << "Rectangle 생성자 (x, y, w, h)" << endl;
    }
    ~Rectangle()

    {
        cout << "Rectangle 소멸자 ()" << endl;
    }
};

int main()
{
    Rectangle r(0, 0, 100, 100);
    return 0;
}