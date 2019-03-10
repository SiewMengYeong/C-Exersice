#include <iostream>
#include <curses.h>

void draw_block(int n,int y,int x);
//void erase_block(int n, int y, int x);

int main()
{
	for (int i=1; i<=7; i++)
	{
		for (int y=0; y<20; y++)
		{
			draw_block(i, y, i);
			refresh();
			usleep(300000);
			//erase_block(i, y, i);)
		}
	}
	return 0;
}

void draw_block(int n,int y,int x)
{
	int i, j;
	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_RED);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_YELLOW);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
 	init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(6, COLOR_WHITE, COLOR_CYAN);
	init_pair(7, COLOR_BLACK, COLOR_WHITE);
	init_pair(8, COLOR_BLACK, COLOR_BLACK);

	int LS[4][2] = { {y,x+5},{y  ,x+7},{y+1,x+7},{y+1,x+9} };
	int RS[4][2] = { {y,x+7},{y  ,x+9},{y+1,x+7},{y+1,x+5} };
	int B [4][2] = { {y,x+6},{y  ,x+8},{y+1,x+6},{y+1,x+8} };
	int LG[4][2] = { {y,x+5},{y+1,x+5},{y+1,x+7},{y+1,x+9} };
	int T [4][2] = { {y,x+6},{y+1,x+4},{y+1,x+6},{y+1,x+8} };
	int RG[4][2] = { {y,x+9},{y+1,x+6},{y+1,x+7},{y+1,x+9} };
	int L [4][2] = { {y,x+4},{y  ,x+6},{y  ,x+8},{y  ,x+10} };

//	while( n < 8 ){

	switch(n)
	{
	case 1:
		for (j = 0;j < 4;j++)
		{
			attron(COLOR_PAIR(1));
			move(LS[j][0],LS[j][1]); printw("  ");
			refresh();
		}
		attroff (COLOR_PAIR(1));
		break;
	case 2:
		for (j = 0;j < 4;j++)
		{
			attron(COLOR_PAIR(2));
			move(RS[j][0],RS[j][1]);printw("  ");
			refresh();				
		}
		attroff (COLOR_PAIR(2));
		break;
	case 3:
		for (j = 0;j < 4;j++)
		{
			attron(COLOR_PAIR(3));
			move( B[j][0], B[j][1]);printw("  ");
		}
		attroff (COLOR_PAIR(3));
		break;
	case 4:
		for (j = 0;j < 4;j++)
		{
			attron (COLOR_PAIR(4));
			move(LG[j][0],LG[j][1]);printw("  ");
			refresh();
		}
		attroff (COLOR_PAIR(4));
		break;
	case 5:
		for (j = 0;j < 4;j++)
		{
			attron (COLOR_PAIR(5));
			move( T[j][0], T[j][1]);printw("  ");
			refresh();
		}
		attroff (COLOR_PAIR(5));
		break;
	case 6:
		for (j = 0;j < 4;j++)
		{
			attron (COLOR_PAIR(6));
			move(RG[j][0],RG[j][1]);printw("  ");
			refresh();
		}
		attroff (COLOR_PAIR(6));
		break;
	case 7:
		for (j = 0;j < 4;j++)
		{
			attron (COLOR_PAIR(7));
			move( L[j][0], L[j][1]);printw("  ");
			refresh();
		}
		attroff (COLOR_PAIR(7));
		break;
	}
	endwin();
	return;
}
