#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;

#include "matrix.h"

int main()
{
    CMatrix a(1);
    CMatrix b(2);
    CMatrix c;

    a.Set(1,1,10);
    b.Set(2,2,100);
    c = a.Add(b);
    c.Print();
    return 0;
}
