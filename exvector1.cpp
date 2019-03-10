#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::string;
//using std::sort;

int main()
{
ifstream fsIn;
fsIn.open("/home/solomon/WWW/Lang/C/vector1.dat");
string n;
int count=0;
vector<string> v;
vector<int> x;
while (fsIn >> n)
    {
        v.push_back(n);
        count++;
    }
for(int i=0;i<v.size();i++)
{
   x.push_back( atoi( v[i].c_str() ));
}

sort(x.begin(),x.end());
for(int i=0;i<x.size();i++)
{
  cout<<i+1<<":"<<'\t'<<x[i];
  cout<<endl;
}
fsIn.close();
return 0;
}
