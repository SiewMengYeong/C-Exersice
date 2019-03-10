#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int n,i;
  cout<<"N=?";
  cin>>n;
  if (n==2 || n==3)
  {
     cout<<n<<" is a prime number."<<endl;
     return 0;
  }
  for (i=2;i<n;)
  {
    if (n%i!=0)
    {
      i++;
      if (n%(i+1)==0 && n==i+1)
        cout<<n<<" is a prime number."<<endl;
    }
    else
    {
      i=n;
      cout<<n<<" is NOT a prime number."<<endl;
    }
  }
  return 0;
}
