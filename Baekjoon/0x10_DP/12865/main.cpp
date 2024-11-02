#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int w[101] = {};
int v[101] = {};
int d[101][100001];

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
  if (a.first == b.first)
    return a.second > b.second;
  return a.first < b.first;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> w[i + 1] >> v[i + 1];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= k; j++)
    {
      if (w[i] <= j)
        d[i][j] = max(d[i-1][j-w[i]] + v[i], d[i-1][j]);
      else
        d[i][j] = d[i-1][j];
    }
  }

  cout << d[n][k];

  return 0;
}