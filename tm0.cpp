#include <iostream>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;

int main ()
{
int y,m,d;
time_t rawtime;
struct tm * timeinfo;

time(&rawtime);
timeinfo=localtime(&rawtime);

cout<<"Date:(yyyy mm dd)";
cin>>y>>m>>d;

timeinfo->tm_year+1900
cout<<year<<endl;
cout<<asctime(timeinfo)<<endl;
return 0;
}
