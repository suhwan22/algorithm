#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int board[50][50];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;

  cin >> n >> m;
  // 2 <= n <= 50, 1 <= m <= 13

  vector<pair<int, int>> chicken;
  vector<pair<int ,int>> home;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j];
      if (board[i][j] == 2)
        chicken.push_back({i, j});
      else if (board[i][j] == 1)
        home.push_back({i, j});
    }
  }

  // 0: 빈칸, 1: 집, 2: 치킨집
  // 두점 사이 거리 |x1 - x2| + |y1 - y1|
  // m개 빼고 치킨집 없앴을때 가능한 최소 치킨 거리

  int size = chicken.size();
  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    if (i < m)
      arr[i] = 0;
    else
      arr[i] = 1;
  }
  // for (int i = 0; i < size; i++)
  //   cout << arr[i] << " ";
  // cout << "\n";

  int min;
  int temp;
  int dis;
  int ans = 2147483647;
  do
  {
    dis = 0;
    for (int i = 0; i < (int)home.size(); i++)
    {
      min = 2147483647;
      for (int j = 0; j < size; j++)
      {
        if (arr[j] == 0)
        {
          temp = abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second);
          // cout << "dis = | " << chicken[j].first << " - " << home[i].first << " | + | " << chicken[j].second << " - " << home[i].second << " | \n";
          if (min > temp)
            min = temp;
        }
      }
      dis += min;
    }
    // cout << "sellect: ";
    // for (int i = 0; i < m; i++)
    // {
    //   if (arr[i] == 0)
    //     cout << "(" << chicken[i].first << ", " << chicken[i].second << ") ";
    // }
    // cout << "\nchicken dis: " << dis << "\n";
    if (ans > dis)
      ans = dis;
  } while (next_permutation(arr.begin(), arr.end()));

  cout << ans;

  return 0;
}