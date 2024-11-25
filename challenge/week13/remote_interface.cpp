#include <iostream>
using namespace std;

class RemoteControl
{
public:
    virtual void TurnON() = 0;
    virtual void TurnOFF() = 0;
};

class Television : public RemoteControl
{
    void TurnON()
    {
        cout << "TV를 켭니다. " << endl;
    }
    void TurnOFF()
    {
        cout << "TV를 끕니다. " << endl;
    }
};

class Refrigerator : public RemoteControl
{
    void TurnON()
    {
        cout << "냉장고를 켭니다. " << endl;
    }
    void TurnOFF()
    {
        cout << "냉장고를 끕니다. " << endl;
    }
};

int main()
{
    RemoteControl* remote_TV = new Television();
    remote_TV->TurnON();
    remote_TV->TurnOFF();

    RemoteControl* remote_refrigerator = new Refrigerator();
    remote_refrigerator->TurnON();
    remote_refrigerator->TurnOFF();

    delete remote_TV, remote_refrigerator;
    return 0;
}