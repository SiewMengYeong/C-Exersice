#include <iostream>
#include <curses.h>

void draw_block(int n,int y,int x);

int main()
{
    
	for (int i=1; i<=7; i++)
    {
        for (int y=0; y<20; y++)
        {
            draw_block(i, y, i);
            refresh();
            usleep(300000);
        }
    }

    
    return 0;
}
void draw_block(int n, int y, int x)
{
	initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
	int LS[4][2] = { {y,x+5},{y  ,x+7},{y+1,x+7},{y+1,x+9} };
    int j;	
	switch(n)
	{
	
	case 1:
	{      
		for (j = 0;j < 4;j++)
		{
		    attron( COLOR_PAIR(n) );
			move(LS[j][0],LS[j][1]); printw("  ");
			attroff( COLOR_PAIR(n) );
		}
	}
	
	}
	endwin();
}
