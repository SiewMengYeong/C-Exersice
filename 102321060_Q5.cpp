#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

int main()
{
const int N=1005000;
int x(1);
cout<<2<<' ';
for(int i=2;i<N;i++)
  for(int j=2;j<=ceil(sqrt(i));j++)
  {
    if (i%j!=0)
    {
      if (i<j*j)
       {
        cout<<i<<' ';
        x++;
       }
    }
    else
      j=i;
  }
cout<<endl<<"the number of prime numbers = "<<x<<endl;
return 0;
}
