#include <ctime>

class CHorse
{
public:
static short unsigned int m_count;

CHorse(int t)
{
y=(t%8==0?8:t%8)+1;
x=START;
m_count++;
move(11, 0);
printw("Total number of horses:%d", m_count);

}

CHorse()
{
srand((unsigned) time(NULL));
y=rand()%8+2;
x=START;
m_count++;
move(11, 0);
printw("Total number of horses:%d", m_count);
}
void Show()
{
if (x>FINISH-10)
{
attron(COLOR_PAIR(COLOR_RED));
move(y,x);addstr(strHorse);
attroff(COLOR_PAIR(COLOR_RED));
}
else
{
move(y,x);addstr(strHorse);
}
}

void Hide()
{
move(y,x);addstr(" ");
}

int Forward()
{
Hide();
x++;
Show();
}
               
bool Final()
{
if(x == FINISH-4 )
return 1;
else
return 0;
}

private:
int x;
int y;

};

//int CHorse::m_count(0);
