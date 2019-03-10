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
m_time=time(NULL);
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

bool Move(Movement x)
{
int c;
switch(x)
{
case down:
{
  if(pos_y<=nBottomBorder-4)
  {
    if(type_id!=0&&pos_y>=nBottomBorder-4)
    {
      return 0;
      break;
    }
    Erase();

    pos_y++;
    Draw();
    refresh();

    if((type_id!=0&&pos_y>=nBottomBorder-4)||(type_id==0&&pos_y>nBottomBorder-4))
    {
      return 0;
      break;
    }

    c=getch();

            switch (c)
            {
                case 'q':
                    return 0;
                    break;
                case KEY_LEFT:
                case 'h':
                    Move(left);
                    return 1;
                    break;
                case KEY_RIGHT:
                case 'l':
                    Move(right);
                    return 1;
                    break;
                case KEY_DOWN:
                    Move(down);
                    return 1;
                    break;
            }
  return 1;
  break;
  }
  else
  {
    return 0;
    break;
  }
}
case left:
{
  Erase();
  if (type_id==0 || type_id==1 || type_id==3)
  {
      if(pos_x>0)
        pos_x--;
  }
  if (type_id==2)
  {
      if(pos_x>2)
        pos_x--;
  }
  if (type_id==4 || type_id==5 || type_id==6)
  {
      if(pos_x>1)
        pos_x--;
  }
  Draw();
    c=getch();

            switch (c)
            {
                case 'q':
                    return 0;
                    break;
                case KEY_LEFT:
                case 'h':
                    Move(left);
                    return 1;
                    break;
                case KEY_RIGHT:
                case 'l':
                    Move(right);
                    return 1;
                    break;
                case KEY_DOWN:
                    Move(down);
                    return 1;
                    break;
            }

  return 1;
  break;
}

case right:
{
  Erase();
  if(pos_x!=nRightBorder)
  if (type_id==0)
  {
    if(pos_x<nRightBorder-1)
        pos_x++;
  }
  if (type_id==1)
  {
    if(pos_x<nRightBorder)
        pos_x++;
  }
  if (type_id==2)
  {
    if(pos_x<nRightBorder+2)
        pos_x++;
  }
  if (type_id>=3 && type_id<=6)
  {
    if(pos_x<nRightBorder+1)
        pos_x++;
  }
  Draw();
    c=getch();

            switch (c)
            {
                case 'q':
                    return 0;
                    break;
                case KEY_LEFT:
                case 'h':
                    Move(left);
                    return 1;
                    break;
                case KEY_RIGHT:
                case 'l':
                    Move(right);
                    return 1;
                    break;
                case KEY_DOWN:
                    Move(down);
                    return 1;
                    break;
            }

  return 1;
  break;
}
}
}

private:
unsigned int m_time;

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

};
