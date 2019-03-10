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
    CMatrix b = a;	
    b.Set(0,0,88);
    a.Print();
    b.Print();
    return 0;
    
}
