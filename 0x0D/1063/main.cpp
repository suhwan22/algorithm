#include <iostream>
#include <queue>

using namespace std;

// 8
// 7
// 6
// 5
// 4
// 3
// 2
// 1
//   a b c d e f g h

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  int q;
  cin >> a >> b >> q;
  pair<int, int> king;
  pair<int, int> stone;
  king = {a[1] - '1', a[0] - 'A'};
  stone = {b[1] - '1', b[0] - 'A'};

  cout << "king x: " << king.first << ", y: " << king.second << "\n";
  cout << "stone x: " << stone.first << ", y: " << stone.second << "\n";

  int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
  int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

  string input;
  int nx, ny;
  int snx, sny;
  while (q--)
  {
    cin >> input;
    if (input == "R")
    {
      nx = king.first + dx[0];
      ny = king.second + dy[0];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[0];
        sny = stone.second + dy[0];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }
    }
    else if (input == "L")
    {
      nx = king.first + dx[1];
      ny = king.second + dy[1];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[1];
        sny = stone.second + dy[1];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }

    }
    else if (input == "B")
    {
      nx = king.first + dx[2];
      ny = king.second + dy[2];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[2];
        sny = stone.second + dy[2];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }

    }
    else if (input == "T")
    {
      nx = king.first + dx[3];
      ny = king.second + dy[3];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[3];
        sny = stone.second + dy[3];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }

    }
    else if (input == "RT")
    {
      nx = king.first + dx[4];
      ny = king.second + dy[4];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[4];
        sny = stone.second + dy[4];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }

    }
    else if (input == "LT")
    {
      nx = king.first + dx[5];
      ny = king.second + dy[5];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[5];
        sny = stone.second + dy[5];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }

    }
    else if (input == "RB")
    {
      nx = king.first + dx[6];
      ny = king.second + dy[6];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[6];
        sny = stone.second + dy[6];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }

    }
    else if (input == "LB")
    {
      nx = king.first + dx[7];
      ny = king.second + dy[7];
      if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
      if (nx == stone.first && ny == stone.second)
      {
        snx = stone.first + dx[7];
        sny = stone.second + dy[7];
        if (snx < 0 || sny < 0 || snx >= 8 || sny >= 8) continue;
        king.first = nx;
        king.second = ny;
        stone.first = snx;
        stone.second = sny;
      }
      else
      {
        king.first = nx;
        king.second = ny;
      }
    }
  }

  cout << (char)(king.second+'A') << king.first + 1 << "\n";
  cout << (char)(stone.second+'A') << stone.first + 1 << "\n";

  return 0;
}