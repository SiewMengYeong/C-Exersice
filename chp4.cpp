#include <iostream>
using std::cout;
using std::endl;

int main()
{
  int p[6]={0};
  int j;
  srand((unsigned)time(NULL));
  for(int i(0);i<20;i++)
  {
    j=rand()%6;
    ++p[j];
  }
  for(int j(0);j<6;j++)
    cout<<j+1<<":"<<p[j]<<endl;
  return 0;
}
