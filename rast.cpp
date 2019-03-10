#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{ 
  int x,y;
//  cout<<x<<endl;
//  cout<<y<<endl;
  cout<<"x,y = ";
  cin>>x>>y;
  if ((x>y)&&(y==0))
  {
     cout<<"true"<<endl;
     cout<<x-y<<endl;
  } 
  else
  {
    cout<<"false"<<endl;
    cout<<y-x<<endl;
  }
  return 0;
}
