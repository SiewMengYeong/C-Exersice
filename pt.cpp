#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int i(1),sum(0);
//  cout<<"N=?";
//  cin>>n;
loop:
  sum+=i;
  if(++i<<10)
    goto loop;
    
  cout<<endl
      <<"sum="<<sum<<endl
      <<"i="<<i<<endl;
  return 0;
}
