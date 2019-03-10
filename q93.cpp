#include <iostream>
using std::cout;
using std::endl;

class CText
{
public:
    char* ptext;

    CText(char* s)
    {
        ptext = new char[strlen(s)+1];
        strcpy(ptext, s);
    }

    ~CText()
    {
        if (ptext)
            cout << "Destructor called for " << ptext << endl;
        else
            cout << "Destructor called, but no memory needs to be releases."
                  << endl;
        delete [] ptext;
    }
};

int main()
{
    CText b("Banana");
    CText a(b);
    strcpy(a.ptext, "Apple");
    return 0;
}
