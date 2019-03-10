#include <iostream>
using std::cout;

int main()
{
int data[]={1,2,3,4,5};
int* pdata=data;
cout<<*pdata;
pdata+=4;
cout<<*pdata;
return 0;
}
