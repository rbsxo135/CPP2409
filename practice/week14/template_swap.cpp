#include <iostream>
using namespace std;

template <typename T>
void swap_value(T& x, T&y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int x = 100, y = 200;
    swap_value(x, y);
    cout << x << " " << y << endl;

    string s1 = "This is a first string";
    string s2 = "This is a second string";
    swap_value(s1, s2);
    cout << s1 << " " << s2 << endl;
    return 0;
}