#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

// 현재 토양에 있는 영양분
int board[11][11] = {};

// 각 토양마다 있는 나무들 나이순으로 오름차순 정렬
deque<int> tree[11][11] = {};

// 각 토양마다 죽은 나무들
deque<int> die[11][11] = {};

// 매 겨울마다 토양에 뿌릴 영양분
int A[11][11] = {};
// 1 <= A[r][c] <= 100

// n: 땅 크기(nxn), m: 나무의 개수, k: k년 지난 후 나무의 개수를 구하는 게 목표
// 1 <= n <= 10
// 1 <= m <= n^2
// 1 <= k <= 1,000
int n, m, k;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void init();
void spring();
void summer();
void autumn();
void winter();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  init();

  while (k--)
  {
    spring();
    summer();
    autumn();
    winter();
  }

  int size = 0;
  for (int x = 1; x <= n; x++)
  {
    for (int y = 1; y <= n; y++)
      size += tree[x][y].size();
  }

  cout << size;

  return 0;
}

void spring()
{
  deque<int>::iterator st;
  for (int x = 1; x <= n; x++)
  {
    for (int y = 1; y <= n; y++)
    {
      st = tree[x][y].begin();
      for (; st != tree[x][y].end(); st++)
      {
        if (board[x][y] >= *st)
        {
          board[x][y] -= *st;
          *st += 1;
        }
        else
          break;
      }
      for (auto it = st; it != tree[x][y].end(); it++)
        die[x][y].push_back(*it);
      tree[x][y].erase(st, tree[x][y].end());
    }
  }
}

void summer()
{
  for (int x = 1; x <= n; x++)
  {
    for (int y = 1; y <= n; y++)
    {
      for (int age : die[x][y])
        board[x][y] += age / 2;
      die[x][y].clear();
    }
  }
}

void autumn()
{
  int nx, ny;
  for (int x = 1; x <= n; x++)
  {
    for (int y = 1; y <= n; y++)
    {
      for (int age : tree[x][y])
      {
        if (age % 5 != 0) continue;
        for (int i = 0; i < 8; i++)
        {
          nx = x + dx[i];
          ny = y + dy[i];
          if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
          tree[nx][ny].push_front(1);
        }
      }
    }
  }
}

void winter()
{
  for (int x = 1; x <= n; x++)
  {
    for (int y = 1; y <= n; y++)
      board[x][y] += A[x][y];
  }
}

void init()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      cin >> A[i][j];
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      board[i][j] = 5;
  }


  int x, y, age;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y >> age;
    tree[x][y].push_back(age);
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      sort(tree[i][j].begin(), tree[i][j].end());
  }
}