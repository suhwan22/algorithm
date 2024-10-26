#include <iostream>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> arr;
  int input;

  for (int i = 0; i < n; i++)
  {
    cin >> input;
    if (input <= k)
      arr.push_back(input);
  }

  int idx = arr.size() - 1;
  int cnt = 0;
  while (k)
  {
    if (arr[idx] <= k)
    {
      k -= arr[idx];
      cnt++;
    }
    else
      idx--;
  }
  cout << cnt;

  return 0;
}