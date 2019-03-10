#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
int m[3][3];
int det;
cout<<"Please input a 3x3 matrix to calculate its determinant:"<<endl;
for (int i(0);i<3;i++)
{
  for (int j(0);j<3;j++)
    cin>>m[i][j];
}
det=m[0][0]*m[1][1]*m[2][2]+m[0][1]*m[1][2]*m[2][0]+m[0][2]*m[1][0]*m[2][1]-    
m[2][0]*m[1][1]*m[0][2]-m[2][1]*m[1][2]*m[0][0]-m[2][2]*m[1][0]*m[0][1];
cout<<"Its determinant is equal to "<<det<<endl;
return 0;
}
