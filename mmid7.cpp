#include <iostream>
using std::cout;

void octal(int n)
{
    if (n >= 8)
        octal( n / 8 );
    cout << n;
}

int main()
{
    octal(20);
    return 0;
}

