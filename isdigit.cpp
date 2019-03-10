#include <iostream>
using std::cout;
using std::endl;

bool isDigit(char c)
{
  if (c>='0' && c<'9')
    return 1;
  else
    return 0;
}

int main()
{
    char str[] = "1A2B.g0v";
    for (int i=0; i< strlen(str); i++)
        if ( isDigit(str[i]) )
            cout << "True" << endl;
        else
            cout << "False" << endl;
    return 0;
}

