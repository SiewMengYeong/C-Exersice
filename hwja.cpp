#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int D,Y;
  cout<<"哪一年? ";
  cin>>Y;
  Y=Y-1;
  D=((Y/400)-(Y/100)+(Y/4)+Y+1)%7;
  cout<<"第一天是星期"<<D<<endl;
  return 0;

}
