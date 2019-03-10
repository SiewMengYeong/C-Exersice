#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int i,a(1),b(1),c,d,n;
  cout<<"n=";
  cin>>n;
  for (i=1;i<=n-2;i++)
   { 
     c=a;
     d=b;
     a=b;
     b=c+d;
   }
   cout<<b<<endl;
   
  return 0;
}
