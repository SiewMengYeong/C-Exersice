#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{ int a,b,c;
  cout<<"a,b=";
  cin>>a>>b;
//  c=a>b?c=a:c=b;
  switch(a)
  {
    case 1:cout<<a<<endl;
           break;
    case 3:
      {  //int count=2;
         cout<<b<<2
             <<1<<endl;
           break;
      }
    default:cout<<"^^"<<endl;
  }
  return 0;
}
