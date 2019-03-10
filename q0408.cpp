# include <iostream>
using std::cout;
using std::endl;

void f(int i)
{
if (i>=7)
  f(i/7);
cout<<i%7;
return;
}
int main()
{
f(49);
cout<<endl;
return 0;
}
