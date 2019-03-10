#include <iostream>
using std::cout; 
using std::endl; 

int main()
{
int i;
for (i=0;i<10;i++)
  cout<<i<<(i%5==0?'\n':'\t');

return 0;
}
