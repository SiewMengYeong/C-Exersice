#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
char pstr[3][4]={{1,2,3,4},{2,5,8,0}};
int count((sizeof pstr)/(sizeof pstr[0]));

cout<<sizeof pstr<<' '<<sizeof pstr[0]<<endl;

return 0;
}

