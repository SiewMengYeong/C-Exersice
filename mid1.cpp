#include <iostream>
using std::cout; 
using std::endl; 

int main()
{
int a[]={12,4,8};
(*a/=*(a+1))+*(a+2);
cout<<a[0]<<endl;

return 0;
}
