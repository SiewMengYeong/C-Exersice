#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
int* p;
int a[]={1,2,3,4,5,6,7};
p=&a[2];
*(p+2)=*(p+4);
for (int i=0;i<7;i++)
cout<<a[i]<<(i!=6?' ':'\n');
return 0;
}
