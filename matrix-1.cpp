#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;

#include "matrix.h"

int main()
{
    CMatrix A(1);
    A.Print();
    A.Set(1,1,10);
    A.Print();

    CMatrix B(2);
    B.Set(2,2,100);
    B.Print();
    return 0;
}
