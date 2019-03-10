#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;

#include "matrix4.h"

int main()
{
    CMatrix a(3,3,1);
    CMatrix b = a;	
    cout<< (sizeof(CMatrix))<<endl;
    b.Set(0,0,88);
    a.Print();
    b.Print();
    return 0;
}

