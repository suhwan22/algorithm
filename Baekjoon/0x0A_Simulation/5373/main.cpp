#include <iostream>

enum { UP, DOWN, FRONT, BEHIND, RIGHT, LEFT };

using namespace std;

int seq[26] = {};
char *side[6][12] = {};   // 각 면의 사이드를 가르킬 포인터
char *surface[6][9] = {}; // 각 면을 가르킬 포인터

char block[6][9] = {};

void initColor();
void initPointer();
void rotation(int e, int dir);
void printCube();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  initPointer();
  seq['U' - 'A'] = UP;
  seq['D' - 'A'] = DOWN;
  seq['F' - 'A'] = FRONT;
  seq['B' - 'A'] = BEHIND;
  seq['R' - 'A'] = RIGHT;
  seq['L' - 'A'] = LEFT;
  int n, m;
  string cmd;
  cin >> n;
  while (n--)
  {
    initColor();
    cin >> m;
    for (int i = 0; i < m; i++)
    {
      cin >> cmd;
      rotation(seq[cmd[0] - 'A'], cmd[1] == '+' ? 0 : 1);
    }
    for (int i = 0; i < 9; i++)
    {
      cout << block[UP][i];
      if (i % 3 == 2)
        cout << "\n";
    }
  }

  return 0;
}

void rotation(int e, int dir)
{
  if (dir == 0)
  {
    // 시계
    int temp = *surface[e][2];
    *surface[e][2] = *surface[e][0];
    *surface[e][0] = *surface[e][6];
    *surface[e][6] = *surface[e][8];
    *surface[e][8] = temp;
    temp = *surface[e][1];
    *surface[e][1] = *surface[e][3];
    *surface[e][3] = *surface[e][7];
    *surface[e][7] = *surface[e][5];
    *surface[e][5] = temp;

    for (int i = 0; i < 3; i++)
    {
      temp = *side[e][5 - i];
      *side[e][5 - i] = *side[e][2 - i];
      *side[e][2 - i] = *side[e][11 - i];
      *side[e][11 - i] = *side[e][8 - i];
      *side[e][8 - i] = temp;
    }
  }
  else
  {
    int temp = *surface[e][2];
    *surface[e][2] = *surface[e][8];
    *surface[e][8] = *surface[e][6];
    *surface[e][6] = *surface[e][0];
    *surface[e][0] = temp;
    temp = *surface[e][1];
    *surface[e][1] = *surface[e][5];
    *surface[e][5] = *surface[e][7];
    *surface[e][7] = *surface[e][3];
    *surface[e][3] = temp;

    for (int i = 0; i < 3; i++)
    {
      temp = *side[e][5 - i];
      *side[e][5 - i] = *side[e][8 - i];
      *side[e][8 - i] = *side[e][11 - i];
      *side[e][11 - i] = *side[e][2 - i];
      *side[e][2 - i] = temp;
    }
  }
}

void initPointer()
{
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 9; j++)
      surface[i][j] = &block[i][j];
  }
  int i = 0;
  side[UP][i++] = &block[RIGHT][2];
  side[UP][i++] = &block[RIGHT][1];
  side[UP][i++] = &block[RIGHT][0];
  side[UP][i++] = &block[FRONT][2];
  side[UP][i++] = &block[FRONT][1];
  side[UP][i++] = &block[FRONT][0];
  side[UP][i++] = &block[LEFT][2];
  side[UP][i++] = &block[LEFT][1];
  side[UP][i++] = &block[LEFT][0];
  side[UP][i++] = &block[BEHIND][2];
  side[UP][i++] = &block[BEHIND][1];
  side[UP][i++] = &block[BEHIND][0];
  i = 0;
  side[DOWN][i++] = &block[RIGHT][6];
  side[DOWN][i++] = &block[RIGHT][7];
  side[DOWN][i++] = &block[RIGHT][8];
  side[DOWN][i++] = &block[BEHIND][6];
  side[DOWN][i++] = &block[BEHIND][7];
  side[DOWN][i++] = &block[BEHIND][8];
  side[DOWN][i++] = &block[LEFT][6];
  side[DOWN][i++] = &block[LEFT][7];
  side[DOWN][i++] = &block[LEFT][8];
  side[DOWN][i++] = &block[FRONT][6];
  side[DOWN][i++] = &block[FRONT][7];
  side[DOWN][i++] = &block[FRONT][8];
  i = 0;
  side[FRONT][i++] = &block[RIGHT][0];
  side[FRONT][i++] = &block[RIGHT][3];
  side[FRONT][i++] = &block[RIGHT][6];
  side[FRONT][i++] = &block[DOWN][2];
  side[FRONT][i++] = &block[DOWN][1];
  side[FRONT][i++] = &block[DOWN][0];
  side[FRONT][i++] = &block[LEFT][8];
  side[FRONT][i++] = &block[LEFT][5];
  side[FRONT][i++] = &block[LEFT][2];
  side[FRONT][i++] = &block[UP][6];
  side[FRONT][i++] = &block[UP][7];
  side[FRONT][i++] = &block[UP][8];
  i = 0;
  side[BEHIND][i++] = &block[LEFT][0];
  side[BEHIND][i++] = &block[LEFT][3];
  side[BEHIND][i++] = &block[LEFT][6];
  side[BEHIND][i++] = &block[DOWN][6];
  side[BEHIND][i++] = &block[DOWN][7];
  side[BEHIND][i++] = &block[DOWN][8];
  side[BEHIND][i++] = &block[RIGHT][8];
  side[BEHIND][i++] = &block[RIGHT][5];
  side[BEHIND][i++] = &block[RIGHT][2];
  side[BEHIND][i++] = &block[UP][2];
  side[BEHIND][i++] = &block[UP][1];
  side[BEHIND][i++] = &block[UP][0];
  i = 0;
  side[RIGHT][i++] = &block[BEHIND][0];
  side[RIGHT][i++] = &block[BEHIND][3];
  side[RIGHT][i++] = &block[BEHIND][6];
  side[RIGHT][i++] = &block[DOWN][8];
  side[RIGHT][i++] = &block[DOWN][5];
  side[RIGHT][i++] = &block[DOWN][2];
  side[RIGHT][i++] = &block[FRONT][8];
  side[RIGHT][i++] = &block[FRONT][5];
  side[RIGHT][i++] = &block[FRONT][2];
  side[RIGHT][i++] = &block[UP][8];
  side[RIGHT][i++] = &block[UP][5];
  side[RIGHT][i++] = &block[UP][2];
  i = 0;
  side[LEFT][i++] = &block[FRONT][0];
  side[LEFT][i++] = &block[FRONT][3];
  side[LEFT][i++] = &block[FRONT][6];
  side[LEFT][i++] = &block[DOWN][0];
  side[LEFT][i++] = &block[DOWN][3];
  side[LEFT][i++] = &block[DOWN][6];
  side[LEFT][i++] = &block[BEHIND][8];
  side[LEFT][i++] = &block[BEHIND][5];
  side[LEFT][i++] = &block[BEHIND][2];
  side[LEFT][i++] = &block[UP][0];
  side[LEFT][i++] = &block[UP][3];
  side[LEFT][i++] = &block[UP][6];
}

void initColor()
{
  int i = 0;
  for (char color : {'w','y','r','o','b','g'})
  {
    for (int j = 0; j < 9; j++)
      block[i][j] = color;
    i++;
  }
}

void printCube()
{
  cout << "--------------\n";
  cout << "UP\n";
  for (int i = 0; i < 9; i++)
  {
    cout << block[UP][i];
    if (i % 3 == 2)
      cout << "\n";
  }
  cout << "FRONT\n";
  for (int i = 0; i < 9; i++)
  {
    cout << block[FRONT][i];
    if (i % 3 == 2)
      cout << "\n";
  }
  cout << "RIGHT\n";
  for (int i = 0; i < 9; i++)
  {
    cout << block[RIGHT][i];
    if (i % 3 == 2)
      cout << "\n";
  }
  cout << "BEHIND\n";
  for (int i = 0; i < 9; i++)
  {
    cout << block[BEHIND][i];
    if (i % 3 == 2)
      cout << "\n";
  }
  cout << "LEFT\n";
  for (int i = 0; i < 9; i++)
  {
    cout << block[LEFT][i];
    if (i % 3 == 2)
      cout << "\n";
  }
  cout << "DOWN\n";
  for (int i = 0; i < 9; i++)
  {
    cout << block[DOWN][i];
    if (i % 3 == 2)
      cout << "\n";
  }
  cout << "--------------\n";
}