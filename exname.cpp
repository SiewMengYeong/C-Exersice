#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    const char* name[] = { "Alice", "Bob", "Charlie", "Dvorak" };
    int i;
    for (i=0; i < sizeof(name) / sizeof(name[0]); i++)
//        show_name_box(name[i]);
//          cout<<type(name[i])<<' '
          cout<<name[i]<<endl;
    return 0;
}

