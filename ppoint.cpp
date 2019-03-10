#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void swap(int&& i,int&& j)
{
int temp;
temp=i;
i=j;
j=temp;
return;
}

int main()
{
int x(3);
int y(5);

cout<<x<<endl;
cout<<y<<endl;
swap(x,y);
cout<<x<<endl;
cout<<y<<endl;
return 0;
}
