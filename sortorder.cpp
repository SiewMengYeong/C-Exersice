#include <iostream>
using std::cout;
using std::endl;

int main()
{
const int MAX=4;
int data[MAX]={3,8,5,0};
int x;

for(int i(0);i<MAX;i++)
  cout<<data[i]<<' ';
cout<<endl;

for(int i(0);i<MAX-1;i++)
{
  for(int j=i+1;j<MAX;j++)
  {
    if (data[i]<data[j])
    {
       x=data[i];data[i]=data[j];data[j]=x;
    }
  }
}
for(int i(0);i<MAX;i++)
  cout<<data[i]<<' ';
cout<<endl;
return 0;
}
