#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
string a=" Yeong Siew Meng";
cout<<a<<endl;
cout<<a.length()<<endl;
string b(7,'a');
cout<<b<<endl;
string c(a,7,4);
cout<<c<<endl;

return 0;
}
