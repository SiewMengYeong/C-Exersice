#include <iostream>
#include <math.h>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  float s,a,b,c,A;
  cout<<"the length of triangle three sides a, b, and c = ";
  cin>>a>>b>>c;
  s = (a + b + c) / 2;
  A = sqrt( s*(s-a)*(s-b)*(s-c) );
  cout<<"the area of a triangle = "<<A<<endl;
  return 0;

}


