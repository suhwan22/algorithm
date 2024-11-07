#include <iostream>
#include <queue>

using namespace std;

int n;
pair<int, int> egg[8] = {};
// 내구도, 무게

int maxEgg = 0;

void dfs(int obj);
bool isOver(int obj);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> egg[i].first >> egg[i].second;


  for (int i = 1; i < n; i++)
  {
    egg[i].first -= egg[0].second;
    egg[0].first -= egg[i].second;
    dfs(1);
    egg[i].first += egg[0].second;
    egg[0].first += egg[i].second;
  }

  cout << maxEgg;

  return 0;
}

void dfs(int obj)
{
  if (isOver(obj) || obj == n)
  {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += egg[i].first > 0 ? 0 : 1;
    if (cnt > maxEgg)
      maxEgg = cnt;
    return;
  }
  if (egg[obj].first <= 0)
  {
    dfs(obj + 1);
    return ;
  }
  for (int i = 0; i < n; i++)
  {
    if (i == obj) continue;
    if (egg[i].first <= 0) continue;
    egg[i].first -= egg[obj].second;
    egg[obj].first -= egg[i].second;
    dfs(obj + 1);
    egg[i].first += egg[obj].second;
    egg[obj].first += egg[i].second;
  }
}

bool isOver(int obj)
{
  for (int i = 0; i < n; i++)
  {
    if (i == obj) continue;
    if (egg[i].first > 0)
      return false;
  }
  return true;
}