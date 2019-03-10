#include <iostream>
#include <iomanip>

using std::hex;
using std::dec;
using std::cout;
using std::endl;

int main()
{
//int i=255;
for(int i=0;i<100;i++)
cout<<dec<<i<<'\t'<<hex<<i<<'\n';

return 0;
}
