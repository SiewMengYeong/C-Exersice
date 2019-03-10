#include <ctime>

struct Tetromino
{
    CSquare s[nSize];
};


class CTetromino
{
public:
unsigned short type_id; // [0..6]
unsigned short pos_x;
unsigned short pos_y;

CTetromino(int id=0,int x=0,int y=0)
{

type_id=id;
pos_x=x;
pos_y=y;
}

Tetromino tetris(int i)
{
Tetromino t[nType] = {
                       0,0, 1,0, 2,0, 3,0 ,
                       0,0, 1,0, 2,0, 0,1 ,
                       0,0, 0,1,-1,0,-2,0 ,
                       0,0, 1,0, 0,1, 1,1 ,
                       0,0, 0,1, 1,0,-1,1 ,
                       0,0, 0,1, 1,0,-1,0 ,
                       0,0, 0,1, 1,1,-1,0
                     };
return t[i];
}

void Draw()
{
attron( COLOR_PAIR(type_id+1) );
for (int j=0;j<nSize;j++)
{
short x=(tetris(type_id)).s[j].dy;
short y=(tetris(type_id)).s[j].dx;
move(y+pos_y+nTopBorder+1,x+pos_x+(nLeftBorder+1)*2);
if(x==y&&y==0)
printw("%d",type_id);
else
addch(' ');
}
attroff( COLOR_PAIR(type_id+1) );
}

void Erase()
{
attron( COLOR_PAIR(0) );
for (int j=0;j<nSize;j++)
{
short x=(tetris(type_id)).s[j].dy;
short y=(tetris(type_id)).s[j].dx;
move(y+pos_y+nTopBorder+1,x+pos_x+(nLeftBorder+1)*2);
addch(' ');
}
attroff( COLOR_PAIR(0) );
}

bool Move(Movement x)
{
if (x==down && pos_y<nBottomBorder-3)
{
  Draw();
  refresh();
  timeout(1000);
  int c;
  c=getch();
  Erase();
  if (c==KEY_DOWN)
    pos_y++;

  pos_y++;

  if (type_id!=0 && pos_y>=nBottomBorder-3  || type_id==0 && pos_y>nBottomBorder-3)
  return 0;

  else
  return 1;
  
}
else
return 0;
}

};
