#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;

int main()
{
int c[100];
ifstream fsin;
fsin.open("/home/solomon/data.txt");
for (int i=0;i<100;i++)
  fsin>>c[i];
fsin.close();

float sum=0;
float average;
for (int i=0;i<100;i++)
  sum+=c[i];
cout<<sum<<endl;
average=sum/100;
cout<<average<<endl;
return 0;
}
