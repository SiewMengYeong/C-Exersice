#include <curses.h> 
#include <unistd.h>

void draw_block(int n, int y0, int x0);
void erase_block(int n, int y0, int x0);
        
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

    attron( COLOR_PAIR(1) );
    move(1, 40); addch(' ');
    move(1, 41); addch(' ');
    move(2, 41); addch(' ');
    move(2, 42); addch(' ');
    attroff( COLOR_PAIR(1) );

    attron( COLOR_PAIR(2) );
    move(4, 41); addch(' ');
    move(4, 42); addch(' ');
    move(5, 40); addch(' ');
    move(5, 41); addch(' ');
    attroff( COLOR_PAIR(2) );
    
    attron( COLOR_PAIR(3) );
    move(7, 40); addch(' ');
    move(7, 41); addch(' ');
    move(8, 40); addch(' ');
    move(8, 41); addch(' ');
    attroff( COLOR_PAIR(3) );

    attron( COLOR_PAIR(4) );
    move(10, 40); addch(' ');
    move(10, 41); addch(' ');
    move(10, 42); addch(' ');
    move(11, 42); addch(' ');
    attroff( COLOR_PAIR(4) );
    
    attron( COLOR_PAIR(5) );
    move(13, 40); addch(' ');
    move(13, 41); addch(' ');
    move(13, 42); addch(' ');
    move(14, 41); addch(' ');
    attroff( COLOR_PAIR(5) );
   
    attron( COLOR_PAIR(6) );
    move(16, 40); addch(' ');
    move(16, 41); addch(' ');
    move(16, 42); addch(' ');
    move(16, 43); addch(' ');
    attroff( COLOR_PAIR(6) );
   
    attron( COLOR_PAIR(7) );
    move(18, 40); addch(' ');
    move(18, 41); addch(' ');
    move(18, 42); addch(' ');
    move(19, 40); addch(' ');
    attroff( COLOR_PAIR(7) );
            
    refresh();


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

void draw_block(int n, int y0, int x0)
{
	attron( COLOR_PAIR(n) );
	if (n==1)
    {        
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');
            move(2+y0, 3+x0); addch(' ');                
	}
	if (n==2)
    {
            move(1+y0, 5+x0); addch(' ');
            move(1+y0, 6+x0); addch(' ');
            move(2+y0, 4+x0); addch(' ');
            move(2+y0, 5+x0); addch(' ');    
	}
	if (n==3)
    {
            move(1+y0, 7+x0); addch(' ');
            move(1+y0, 8+x0); addch(' ');
            move(2+y0, 7+x0); addch(' ');
            move(2+y0, 8+x0); addch(' ');    
	}
	if (n==4)
    {
            move(1+y0, 9+x0); addch(' ');
            move(1+y0, 10+x0); addch(' ');
            move(1+y0, 11+x0); addch(' ');
            move(2+y0, 11+x0); addch(' ');    
	}
	if (n==5)
    {
            move(1+y0, 12+x0); addch(' ');
            move(1+y0, 13+x0); addch(' ');
            move(1+y0, 14+x0); addch(' ');
            move(2+y0, 13+x0); addch(' ');    
	}
	if (n==6)
    {
            move(1+y0, 15+x0); addch(' ');
            move(1+y0, 16+x0); addch(' ');
            move(1+y0, 17+x0); addch(' ');
            move(1+y0, 18+x0); addch(' ');    
	}
	if (n==7)
    {
            move(1+y0, 19+x0); addch(' ');
            move(1+y0, 20+x0); addch(' ');
            move(1+y0, 21+x0); addch(' ');
            move(2+y0, 19+x0); addch(' ');    
	}
	attroff( COLOR_PAIR(n) );
}

void erase_block(int n, int y0, int x0)
{
	attron( COLOR_PAIR(0) );
	if (n==1)
        {       
            move(1+y0, 1+x0); addch(' ');
            move(1+y0, 2+x0); addch(' ');
            move(2+y0, 2+x0); addch(' ');
            move(2+y0, 3+x0); addch(' ');              
	}
	if (n==2)
        {
            move(1+y0, 5+x0); addch(' ');
            move(1+y0, 6+x0); addch(' ');
            move(2+y0, 4+x0); addch(' ');
            move(2+y0, 5+x0); addch(' ');    
	}
	if (n==3)
        {
            move(1+y0, 7+x0); addch(' ');
            move(1+y0, 8+x0); addch(' ');
            move(2+y0, 7+x0); addch(' ');
            move(2+y0, 8+x0); addch(' ');    
	}
	if (n==4)
        {
            move(1+y0, 9+x0); addch(' ');
            move(1+y0, 10+x0); addch(' ');
            move(1+y0, 11+x0); addch(' ');
            move(2+y0, 11+x0); addch(' ');    
	}
	if (n==5)
        {
            move(1+y0, 12+x0); addch(' ');
            move(1+y0, 13+x0); addch(' ');
            move(1+y0, 14+x0); addch(' ');
            move(2+y0, 13+x0); addch(' ');    
	}
	if (n==6)
        {
            move(1+y0, 15+x0); addch(' ');
            move(1+y0, 16+x0); addch(' ');
            move(1+y0, 17+x0); addch(' ');
            move(1+y0, 18+x0); addch(' ');    
	}
	if (n==7)
        {
            move(1+y0, 19+x0); addch(' ');
            move(1+y0, 20+x0); addch(' ');
            move(1+y0, 21+x0); addch(' ');
            move(2+y0, 19+x0); addch(' ');  
	}
	attroff( COLOR_PAIR(0) );
}
