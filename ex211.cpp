#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int n,i,sum(0);
  cout<<"N=?";
  cin>>n;
  for (i=1;i<n;i++)
  {
    cout<<i<<"+";
    sum+=i;
  }
  cout<<n<<"="<<sum+n<<endl;
  return 0;
}
  

