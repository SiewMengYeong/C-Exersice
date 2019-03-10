#include <iostream>
using std::cout;
using std::endl;

int gcd(int a, int b);

void show_gcd(int a, int b)
{
    cout << "gcd(" << a << ',' << b << ")=";
    cout << gcd(a, b) << endl;
    return;
}

int main()
{
    int data[] = { 4, 2, 2, 4, 6, 4, 12, 8, 39, 6, 39, 7, 48, 36 };
    int* p = data;
    for (int i=0; i< sizeof(data)/sizeof(data[0]); i+=2)
        show_gcd(data[i], data[i+1]);
    return 0;
}
