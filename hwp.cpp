#include <iostream>
#include <iomanip>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
  int n,i,j,a(1);
  cout<<"N=?";
  cin>>n;
  if (n>2)
    a++;
  for (i=2;i<=n;i++)
   {
    for (j=2;j<=floor(sqrt(i));)
     {
      if (i%j!=0)
      {
        if (j==floor(sqrt(i)))
         {
          cout<<setw(8)<<i;
          a++;
          if (a%5==0)
            cout<<endl;
         }
        j++;
      }
      else
        j=i;
     }
   }
  cout<<"There are "<<a<<" prime numbers."<<endl;
  return 0;
}

