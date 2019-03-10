
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  float m,h,b;
  cout<<"Input: mass (in kg) and height (in m).";
  cin>>m>>h;
  b=m/(h*h);
  cout<<"BMI="<<b<<endl;
  return 0;
}
