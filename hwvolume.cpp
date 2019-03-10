#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  float r,v,a,pi;
  cout<<"R = ?";
  cin>>r;
  pi=3.14159;
  v=(4.0/3.0)*pi*r*r*r;
  a=4*pi*r*r;
  cout<<"Volume = ";
  cout<<v<<endl;
  cout<<"Area = ";
  cout<<a<<endl;
  return 0;
}
