#include <iostream> 
#include <iomanip>

using std::hex; 
using std::cout; 
using std::endl; 

int main()
{
//int a=(((16<<8)|20)<<8|30)<<8|40;
int a;
a=16<<8;
cout<<hex<<a<<endl;

a=(16<<8)|20;
cout<<hex<<a<<endl;

//cout<<(8|30)<<endl;

a=((16<<8)|20)<<8|30;
cout<<hex<<a<<endl;

//cout<<(8|40)<<endl;

a=(((16<<8)|20)<<8|30)<<8|40;
cout<<hex<<a<<endl;

return 0;
}
