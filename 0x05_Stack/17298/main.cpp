#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  int h;
  stack<pair<int, int>> s;
  int *arr = new int[n];

  for (int i = 0; i < n; i++)
  {
    cin >> h;
    while (!s.empty() && s.top().first < h)
    {
      // cout << "current s.top().second = " << s.top().second << "\n";
      arr[s.top().second] = h;
      s.pop();
    }
    s.push({h, i});
  }
  if (!s.empty())
  {
    for (;s.size();s.pop())
      arr[s.top().second] = -1;
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  delete[] arr;

  return 0;
}