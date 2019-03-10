#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{
  int i;
  for (i=1;i<=12;i++)
   {
    if ((i-1)%5==0)
      cout<<endl;
    cout<<i<<setw(8);
   }
  cout<<endl;
  return 0;
}
