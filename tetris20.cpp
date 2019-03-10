#include <curses.h> 
#include <unistd.h>

void tetris(int n, int y0, int x0)
{
	if (n==1)
        {        
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');
            move(2+y0, 3+x0); addch(' ');                
	}
	if (n==2)
        {
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 1+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');    
	}
	if (n==3)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(2+y0, 1+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');    
	}
	if (n==4)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 3+x0); addch(' ');    
	}
	if (n==5)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');    
	}
	if (n==6)
        {
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(1+y0, 4+x0); addch(' ');    
	}
	if (n==7)
        { 
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(1+y0, 3+x0); addch(' ');
            move(2+y0, 1+x0); addch(' ');    
	}
	return;
}

void draw_block(int n, int y0, int x0)
{
	x0=(x0-1)*3;
	attron( COLOR_PAIR(n) );
	tetris(n,y0,x0);
	attroff( COLOR_PAIR(n) );
}

void erase_block(int n, int y0, int x0)
{
	x0=(x0-1)*3;
	attron( COLOR_PAIR(0) );
	tetris(n,y0,x0);
	attroff( COLOR_PAIR(0) );
	return;
}
        
int main()
{
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);

	for(int n=1;n<=7;n++)
	{
		attron( COLOR_PAIR(n) );
	    tetris(n,(n-1)*3,25);
		attroff( COLOR_PAIR(n) );
		refresh();
	}

    for (int i=1; i<=7; i++)
    {
        for (int y=0; y<20; y++)
        {
            draw_block(i, y, i);
            refresh();
            usleep(300000);
            erase_block(i, y, i);
        }
    }

    endwin();
    return 0;
}


