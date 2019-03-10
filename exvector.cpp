#include <iostream>
#include <vector>
//#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
//using std::string;
using std::sort;

int main()
{
vector<int> n;
for(int i=10;i>0;i--)
  n.push_back(i);
sort(n.begin(),n.end());

for(int j=0;j<n.size();j++)
  cout<<n[j]<<endl;

return 0;
}
