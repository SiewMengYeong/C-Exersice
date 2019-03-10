#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
int x;
const int MAX(80);
char buffer[MAX];

cout<<"write a message. "<<endl;
cin.getline(buffer,MAX,'\n');
cout<<"key=";
cin>>x;

for(int j=0;j<x;j++)
{
for(int i=0;i<strlen(buffer);i++)
{
  if (i%x==j)
    cout<<buffer[i];
}
}
cout<<endl;
return 0;
}
