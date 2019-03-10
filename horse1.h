class CHorse
{
public:
static int m_count;

CHorse(int t=rand()%8+1)
{
y=(t%8==0?8:t%8);
x=START;
m_count++;
}

void Show()
{
move(y,x);addstr(strHorse);
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
if(x == FINISH )
return 1;
else
return 0;
}

private:
int x;
int y;

};

int CHorse::m_count(0);
