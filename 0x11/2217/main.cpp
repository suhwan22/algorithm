#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int idx;
  for (int i = 0; i < n; i++)
  {
    cin >> idx;
    arr[idx]++;
  }

  int w = 0;
  int cnt = 0;
  for (int i = 10000; i > 0; i--)
  {
    cnt += arr[i];
    if (arr[i] != 0 && w < i * cnt)
        w = i * cnt;
  }
  cout << w;

  return 0;
}