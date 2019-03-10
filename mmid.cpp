#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void f(int x)
{
if (x>=2)
  f(x/2);
cout<<x%2;
}

int main()
{
    int x;
    cout<<"x=";
    cin>>x;
    f(x);
    cout<<endl;
    return 0;

}

