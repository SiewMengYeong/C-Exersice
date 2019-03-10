#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;

#include "matrix.h"

int main()
{
    CMatrix a(3,3,1);
    CMatrix b(3,3,2);

    CMatrix c = a.Augment(b);
    c.Print();

    Identity(3).Print();
    a.Augment( Identity(3) ).Print();

    return 0;
}

