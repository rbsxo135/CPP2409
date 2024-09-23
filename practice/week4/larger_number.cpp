#include <iostream>
using namespace std;

int main(void){
    int x, y;

    cout << "put x value: ";
    cin >> x;

    cout << "put y value: ";
    cin >> y;

    if(x > y)
        cout << "x is larger than y" << endl;
    else if (x == y)
        cout << "Both value is same" << endl;
    else
        cout << "y is larger than x" << endl;
    
    return 0;
}