#include <iostream>
#include <fstream>

using std::ofstream;

int main()
{
int c[10]={1,3,5,7,9,10,12,14,16,18};
ofstream fsout;
fsout.open("fname.txt");
for (int i=0;i<10;i++)
fsout<<c[i]<<'\n';
fsout.close();

return 0;
}

