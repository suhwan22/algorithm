#include <iostream>

using namespace std;

unsigned char gear[5];

void run(int p, int dir);
bool isTied(int idx1, int idx2);
void rot(int p, int dir);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  // 톱니가 8개
  // 10101111
  // 01111101
  // 11001110
  // 00000010

  // (1)2 6(2)2 6(3)2 6(4)
  // 0 == 10000000
  // 1 == 01000000
  // 2 == 00100000
  // ...


  string input;
  for (int i = 1; i <= 4; i++)
  {
    cin >> input;
    for (int j = 0; j < 8; j++)
    {
      gear[i] |= (unsigned char)(input[j] - '0');
      if (j != 7)
        gear[i] <<= 1;
    }
  }

  for (int i = 1; i <= 4; i++)
  {
    unsigned char mask = 0b10000000;
    for (int j = 0; j < 8; j++)
    {
      cout << ((mask & gear[i]) > 0) << " ";
      mask >>= 1;
    }
    cout << "\n";
  }

  int k;
  cin >> k;
  int p, dir;
  while (k--)
  {
    cin >> p >> dir;
    // p 1 ~ 4 : 톱니바퀴 번호
    // dir == 1 : 시계방향
    //       -1 : 반시계
    run(p, dir);
    for (int i = 1; i <= 4; i++)
    {
      unsigned char mask = 0b10000000;
      for (int j = 0; j < 8; j++)
      {
        cout << ((mask & gear[i]) > 0) << " ";
        mask >>= 1;
      }
      cout << "\n";
    }
  }
  cout << ((gear[1] & 0b10000000) > 0 ? 1 : 0) + ((gear[2] & 0b10000000) > 0 ? 2 : 0)
          + ((gear[3] & 0b10000000) > 0 ? 4 : 0) + ((gear[4] & 0b10000000) > 0 ? 8 : 0);

  return 0;
}

void run(int p, int dir)
{
  bool onetwo = isTied(1, 2);
  bool twothree = isTied(2, 3);
  bool threefour = isTied(3, 4);
  if (p == 1)
  {
    rot(1, dir);
    if (onetwo)
    {
      rot(2, -1 * dir);
      if (twothree)
      {
        rot(3, dir);
        if (threefour)
          rot(4, -1 * dir);
      }
    }
  }
  else if (p == 2)
  {
    rot(2, dir);
    if (onetwo)
      rot(1, -1 * dir);
    if (twothree)
    {
      rot(3, -1 * dir);
      if (threefour)
        rot(4, dir);
    }
  }
  else if (p == 3)
  {
    rot(3, dir);
    if (threefour)
      rot(4, -1 * dir);
    if (twothree)
    {
      rot(2, -1 * dir);
      if (onetwo)
        rot(1, dir);
    }
  }
  else if (p == 4)
  {
    rot(4, dir);
    if (threefour)
    {
      rot(3, -1 * dir);
      if (twothree)
      {
        rot(2, dir);
        if (onetwo)
          rot(1, -1 * dir);
      }
    }
  }
}

bool isTied(int idx1, int idx2)
{
  return (gear[idx1] & 0b00100000) ^ ((gear[idx2] & 0b00000010) << 4);
}

void rot(int p, int dir)
{
  unsigned char temp;
  if (dir == 1)
  {
    temp = (gear[p] & 0b00000001) > 0 ? 0b10000000 : 0b00000000;
    gear[p] >>= 1;
    gear[p] |= temp;
  }
  else if (dir == -1)
  {
    temp = (gear[p] & 0b10000000) > 0 ? 0b00000001 : 0b00000000;
    gear[p] <<= 1;
    gear[p] |= temp;
  }
}