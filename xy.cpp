#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int x,y;
  float a,b,c;
  float d,e,f;
  cout<<"a system of linear equations of two variables x and y."<<endl;
  cout<<"ax+by=c,dx+ey=f"<<endl;
  cout<<"a?";
  cin>>a;
  cout<<"b?";
  cin>>b;
  cout<<"c?";
  cin>>c;
  cout<<"d?";
  cin>>d;
  cout<<"e?";
  cin>>e;
  cout<<"f?";
  cin>>f;
  x=(c*e-b*f)/(a*e-b*d);
  y=(c*d-a*f)/(b*d-a*e);
  cout<<"x=";
  cout<<x<<endl;
  cout<<"y=";
  cout<<y<<endl; 
  return 0;
}
