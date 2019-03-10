#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main()
{
        int a;
        int b;
        cout << "Input your birth month and day, separated by a space -- ";
        cin >> a >> b;
        if (b<0 || b>31)
        {
                cout << "Please check your birth day." << endl;
                cout << "Input your birth month and day, separated by a space -- ";
                cin >> a >> b;
        }
	 
	if (a == 1)
        {
                if (b < 20)
                        cout << "Capricorn" << endl;
                else
                        cout << "Aquarius" << endl;
        }
        if (a == 2)
        {
                if (b < 19)
                        cout << "Aquarius" << endl;
                else
                        cout << "Pisces" << endl;
        }
	 if (a == 3)
        {
                if (b < 21)
                        cout << "Pisces" << endl;
                else
                        cout << "Aries" << endl;
        }
        if (a == 4)
        {
                if (b < 20)
                        cout << "Aries" << endl;
                else
                        cout << "Taurus" << endl;
        }
	if (a == 5)
        {
                if (b < 21)
                        cout << "Taurus" << endl;
                else
                        cout << "Gemini" << endl;
        }
        if (a == 6)
        {
                if (b < 22)
                        cout << "Gemini" << endl;
                else
                        cout << "Cancer" << endl;
        }
	 if (a == 7)
        {
                if (b < 23)
                        cout << "Cancer" << endl;
                else
                        cout << "Leo" << endl;
        }
        if (a == 8)
        {
                if (b < 23)
                        cout << "Leo" << endl;
                else
                        cout << "Virgo" << endl;
        }
	 if (a == 9)
        {
                if (b < 23)
                        cout << "Virgo" << endl;
                else
                        cout << "Libra" << endl;
        }
        if (a == 10)
        {
                if (b < 23)
                        cout << "Libra" << endl;
                else
                        cout << "Scorpio" << endl;
        }
        if (a == 11)
        {
                if (b < 22)
                        cout << "Scorpio" << endl;
                else
                        cout << "Sagittarius" << endl;
        }
	 if (a == 12)
        {
                if (b < 22)
                        cout << "Sagittarius" << endl;
                else
                        cout << "Capricorn" << endl;
        }
        return 0;
}
