#include <iostream>

void swap(int &i, int &j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
    return;
}

int main()
{
    int a = 4;
    int b = 19;
    std::cout << a << b << std::endl;
    swap(a, b);
    std::cout << a << b << std::endl;
    return 0;
}

