
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
vector<int> n;
for(int i=0;i<10;i++)
  n.push_back(i);

for(int i=0;i<n.size();i++)
  cout<<n[i]<<endl;

return 0;
}
