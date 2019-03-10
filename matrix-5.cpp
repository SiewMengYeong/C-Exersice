#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;

#include "matrix.h"

int main()
{
    CMatrix a(3,4,1);
    CMatrix b(3,4,2);

    a.Set(1,1,10);
    b.Set(2,2,100);

    CMatrix c = a.Add(b);
    c.Print();
    c.Transpose().Print();

    return 0;
}

