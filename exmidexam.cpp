#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

#include <iostream>

int main()
{
const long MAX=5;
int* pnumber;
int number(99);
pnumber=&number;
cout<<MAX<<endl;
cout<<number<<endl;
cout<<*pnumber<<endl;
return 0;
}

