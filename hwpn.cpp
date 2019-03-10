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
  for (i=2;i<=n;i++)
  {
  if (n%i==0)
    cout<<i<<' ';
  }
  cout<<endl;
  return 0;
}

