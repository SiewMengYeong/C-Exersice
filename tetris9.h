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
static bool occupied[nBottomBorder - nTopBorder -1][nRightBorder - nLeftBorder - 1];

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

bool Move(Movement x)
{
for (int k=0;k<nRightBorder - nLeftBorder - 1;k++)
  if ((detect_confliction(0,k)))
  {
    Draw();
    move(nTopBorder + 1, nRightBorder*2 + 2);
    addstr("Game Over!");
    refresh();
    echo();
    endwin();
    _Exit(0);
  }

  for (int i=0;i<nSize;i++)
  {
    short y0=tetris(type_id).s[i].dx+pos_y;
    short x0=tetris(type_id).s[i].dy+pos_x;

    if ((detect_confliction(y0+1,x0)))
    {
    for (int j=0;j<nSize;j++)
    {
      short y=tetris(type_id).s[j].dx+pos_y;
      short x=tetris(type_id).s[j].dy+pos_x;
      update_occupy(y,x);
    }

    return 0;
    break;
    }
  }

switch(x)
{
case down:
{
  Draw();
  if(pos_y<=nBottomBorder-4)
  {
    if(type_id!=0&&pos_y>=nBottomBorder-4)
    {
    for (int j=0;j<nSize;j++)
    {
      short y=tetris(type_id).s[j].dx+pos_y;
      short x=tetris(type_id).s[j].dy+pos_x;
      update_occupy(y,x);
    }
      return 0;
      break;
    }
    Erase();
    pos_y++;
    Draw();
    return 1;
    break;
  }
  else
  {
  for (int j=0;j<4;j++)
  {
    short y=tetris(type_id).s[j].dx+pos_y;
    short x=tetris(type_id).s[j].dy+pos_x;
    update_occupy(y,x);
  }
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
  return 1;
  break;
}

case right:
{
  Erase();
  if (type_id==0)
  {
    if(pos_x<nRightBorder-nLeftBorder-5)
        pos_x++;
  }
  if (type_id==1)
  {
    if(pos_x<nRightBorder-nLeftBorder-4)
        pos_x++;
  }
  if (type_id==2)
  {
    if(pos_x<nRightBorder-nLeftBorder-2)
        pos_x++;
  }
  if (type_id>=3 && type_id<=6)
  {
    if(pos_x<nRightBorder-nLeftBorder-3)
        pos_x++;
  }
  Draw();
  return 1;
  break;
}
}
}

bool detect_confliction(int i,int j)
{
 return occupied[i][j];
}

void update_occupy(int i,int j)
{
  occupied[i][j]=1;
  return;
}


private:
void Draw()
{
  attron( COLOR_PAIR(type_id+1) );
  for (int j=0;j<nSize;j++)
  {
    short x=(tetris(type_id)).s[j].dy;
    short y=(tetris(type_id)).s[j].dx;
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2+1);addch(' ');
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2);
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
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2);addch(' ');
    move(y+pos_y+nTopBorder+1,(x+pos_x+nLeftBorder+1)*2+1);addch(' ');
  }
  attroff( COLOR_PAIR(0) );
}

};

bool CTetromino::occupied[nBottomBorder - nTopBorder -1][nRightBorder - nLeftBorder - 1]={0};
