#include <iostream>
using std::cout;
using std::endl;

class CCircle
{
public:
    int x;
    int y;
    int r;

    CCircle(int a, int b, int c)
    {
        x = a;
        y = 5;
        r = c;
    }
};

int main()
{
    CCircle aCircle(10, 10, 5);
    CCircle* pCircle = &aCircle;
    cout << aCircle.x * pCircle->r  << endl;
    return 0;
}
