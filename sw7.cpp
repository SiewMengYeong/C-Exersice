#include <iostream>

using std::cout;
using std::endl; 
using std::cin;

int main()
{
int x;
cout<<"x=";
cin>>x;

switch(x)
{
case (1):
{
int a=1;
cout<<"happy meal"<<endl;
cout<<"0.0"
    <<endl;
break;
}
case 2:cout<<"breakfast"<<endl;
       break;
case 3:cout<<"lunch"<<endl;
       break;
default:cout<<"0.0"<<endl;
}
return 0;
}
