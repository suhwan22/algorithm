#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int arr[6][2] = {};

  int n, k;
  cin >> n >> k;

  int s, y, cnt = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> s >> y;

    if (arr[y - 1][s] >= k)
    {
      arr[y - 1][s] = 1;
      cnt++;
    }
    else
      arr[y - 1][s]++;
  }

  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      if (arr[i][j] != 0)
        cnt++;
    }
  }

  cout << cnt;

  return 0;
}