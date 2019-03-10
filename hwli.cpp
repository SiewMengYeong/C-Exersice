#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  float x,y,a1,a2,b1,b2,c1,c2;
  cout<<"a1 x + b1 y = c1, a2 x + b2 y = c2"<<endl;
  cout<<"a1 b1 c1 a2 b2 c2 = ";
  cin>>a1>>b1>>c1>>a2>>b2>>c2;
  x=(c1*b2-b1*c2)/(a1*b2-b1*a2);
  y=(c1*a2-a1*c2)/(b1*a2-a1*b2);
  cout<<"x="<<x<<endl;
  cout<<"y="<<y<<endl;
  return 0;
}
