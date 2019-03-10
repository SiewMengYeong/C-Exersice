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

for(int i(0);i<K-1;i++)
{
  for(int j=i+1;j<K;j++)
  {
    if (A[i]>A[j])
    {
       x=A[i];A[i]=A[j];A[j]=x;
    }
    if (B[i]>B[j])
    {
       x=B[i];B[i]=B[j];B[j]=x;
    }     
  }
}

int* pa=A;
int* pb=B;
int* pc=C;

while (pa<A+K && pb<A+K)
{
  if(*pa<=*pb)
    *(pc++)=*(pa++);
  else
    *(pc++)=*(pb++);
}

if (pa<A+K)
{ 
  while(pa<A+K)
    *(pc++)=*(pa++);
}
else
{
  while(pb<A+K)
    *(pc++)=*(pb++);
}
t2=time(NULL);
for(int i(0);i<2*K;i++)
  cout<<C[i]<<' ';
cout<<endl;
cout<<t2-t1<<" seconds."<<endl;
return 0;
}
