#include <iostream>
using std::cout;
using std::endl;

struct Circle
{
    int x;
    int y;
    int radius;
};

void MoveCircle(Circle& aCircle, int x, int y);

int main()
{
    Circle a = { 10, 10, 5};
    MoveCircle(a, 20, 30);
    cout << a.x << endl;
    return 0;
}

void MoveCircle(Circle& aCircle, int x, int y)
{
    aCircle.x = x;
    aCircle.y = y;
    return;
}
