#include <iostream>
#include <ctime>
using std::cout;
using std::endl;

int main()
{
unsigned int t1,t2;
t1=time(NULL);
const int K=100000;
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
for(int i(0);i<K;i++)
  *(pc++)=*(pa++);

for(int i(0);i<K;i++)
  *(pc++)=*(pb++);

pc=C;

for(int i(0);i<2*K-1;i++)
{
  for(int j=i+1;j<2*K;j++)
  {
    if (pc[i]>pc[j])
    {
       x=pc[i];pc[i]=pc[j];pc[j]=x;
    }
  }
}
t2=time(NULL);
for(int i(0);i<2*K;i++)
  cout<<C[i]<<' ';
cout<<endl;
cout<<(t2-t1)<<" seconds."<<endl;
return 0;
}
