#include <iostream>

using std::cout;
using std::endl;

int main()
{
int a=5;
cout<<(a-=2?a:a=2);
cout<<--a<<endl;
return 0;
}


