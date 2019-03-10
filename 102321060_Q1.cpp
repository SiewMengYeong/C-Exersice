#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
for (int c=0;c<10;c++)
  for (int b=0;b<10;b++)
    for (int a=1;a<10;a++)
     
      if (a*a*a*c==a*b*b*a && a!=b && b!=c && a!=c)
        cout<<a<<a<<a<<c<<' '<<a<<b<<b<<a<<endl;
     
return 0;
}
