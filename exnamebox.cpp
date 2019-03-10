#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

void print_line(int y)
{
  for(int i=0;i<y;i++)
    cout<<'=';
  cout<<endl;
  return;
}

void show_name_box(const char x[])
{
  print_line(strlen(x));
  cout<<x<<endl;
  print_line(strlen(x));
  cout<<endl;
  return;
}

int main()
{
    const char* name[] = { "Alice", "Bob", "Charlie", "Dvorak" };
    int i;
    for (i=0; i < sizeof(name) / sizeof(name[0]); i++)
        show_name_box(name[i]);
    return 0;
}
  

