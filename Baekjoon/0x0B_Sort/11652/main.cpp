#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<long long> arr(n);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  arr.push_back(numeric_limits<long long>::max());
  sort(arr.begin(), arr.end());
  long long pre = arr[0];
  int cnt = 0;
  int max = -1;
  long long maxV = pre;
  for (long long ll : arr)
  {
    if (pre == ll)
      cnt++;
    else
    {
      if (max < cnt)
      {
        max = cnt;
        maxV = pre;
      }
      cnt = 1;
      pre = ll;
    }
  }

  cout << maxV;

  return 0;
}