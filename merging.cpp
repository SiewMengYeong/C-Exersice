#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

int main()
{
unsigned int t1,t2;
t1=time(NULL);
const int K=10;
int A[K],B[K],C[K];
srand((unsigned)time(NULL));
int x;
for(int i(0);i<K;i++)
{
  A[i]=rand()%100;
  B[i]=rand()%100;
}
int* pa=A;
int* pb=B;
int* pc=C;

for(int i(0);i<K-1;i++)
{
  for(int j=i+1;j<K;j++)
  {
    if (pa[i]>pa[j])
    {
       x=pa[i];pa[i]=pa[j];pa[j]=x;
    }
    if (pb[i]>pb[j])
    {
       x=pb[i];pb[i]=pb[j];pb[j]=x;
    }     
  }
}
t2=time(NULL);

for(int i(0);i<K;i++)
  cout<<A[i]<<" ";
cout<<endl;

for(int i(0);i<K;i++)
  cout<<B[i]<<" ";
cout<<endl;

cout<<(t2-t1)<<" seconds."<<endl;
return 0;
}
