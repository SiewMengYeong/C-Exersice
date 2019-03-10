#include <iostream>
#include <iomanip>
#include <cmath>
using std::cout;
using std::endl;
using std::setw;

class CMatrix
{
public:
/*unsigned short m_Row;
unsigned short m_Column;
unsigned short m_R;
unsigned short m_C;
*/
unsigned short m_R;
unsigned short m_Ro;
int* entry;
};
int main()
{
 cout<< (sizeof(CMatrix))<<endl;
 return 0;
}
