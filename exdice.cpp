#include <iostream>

using std::cout;
using std::endl;

int main()

{
    int p[6] = { 0 };
    int i,j;
    srand((unsigned) time(NULL));

    for (int k = 0; k < 20; k++ )
    {
        i = rand() % 6;
        ++p[i];
    }

    cout << "Statistics of pips:" << endl;
    for (i=0; i<6; i++)
    {
        cout << i + 1 << ": " << p[i] <<" ";
        for (j=0;j<p[i];j++)
          cout<<"*";
        cout<<endl;
    }
    return 0;

}
