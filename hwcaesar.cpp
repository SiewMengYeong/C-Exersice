#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
int x,i(0);
const int MAX(80);
char buffer[MAX]={0};
cout<<"Plaintext - ";
cin.getline(buffer,MAX,'\n');
cout<<"key - ";
cin>>x;
while (i<MAX)
{
  if (buffer[i]!=0)
{
    buffer[i]+=x;
    buffer[i]=((buffer[i]-65)%26)+65;
}
  i++;
}
cout<<buffer<<endl;
return 0;
}
