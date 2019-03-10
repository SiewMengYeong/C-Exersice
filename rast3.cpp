#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{ 
  int i(1),sum(0);
//  const int max(10);

//loop:
//  sum+=i;
//  if(++i<=10)
//    goto loop;
  for(i=1;i<=10;i++)
    sum+=i;

  cout<<endl<<"sum="<<sum<<endl
      <<"i="<<i<<endl;
  return 0;
}
