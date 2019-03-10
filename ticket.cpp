#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
  int x; 
  cout<<"Ticket=";
  cin>>x;
  cout<<"The transaction will issue "<<x<<((x>1)?" tickets.":" ticket.")<<endl;
  return 0;
}

