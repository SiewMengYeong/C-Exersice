#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int a,k,x,y;
  cout<<"Input the number of animals and the total number of legs, separated by spaces -- ";
  cin>>a>>k;
  x=(4*a-k)/2;
  y=(k-2*a)/2;
  cout<<"There are "<<x<<" chicken(s) and "<<y<<" rabbit(s)."<<endl;
  return 0;
}
