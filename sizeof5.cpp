#include <iostream>

using std::cout; 
using std::endl; 

int main()
{
const char* name[] = { "Aliceabcdefg", "Bob", "Charlie", "Dvorak" };
const char* ma[]={"1","2","4","77","99"};
const char a[]={'1','2','4','7','9'};
cout<<sizeof(name)<<endl;
cout<<sizeof(name[0])<<endl;
cout<<strlen(name[0])<<endl;
cout<<sizeof("yeong siew meng")<<endl;
cout<<strlen("yeong siew meng")<<endl;
cout<<sizeof(ma)<<endl;
cout<<sizeof(ma[3])<<endl;
cout<<strlen(ma[3])<<endl;
cout<<strlen(ma[0])<<endl;
cout<<sizeof("100")<<endl;
cout<<strlen("100")<<endl;
cout<<sizeof("yeongsiewmeng")<<endl;
cout<<sizeof(a)<<endl;
cout<<sizeof(a[3])<<endl;

return 0;
}
