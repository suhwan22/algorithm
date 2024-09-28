#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<pair<int, int> > s;
  s.push({100000001, 0});
  int h;

  for (int i = 1; i <= n; i++)
  {
    cin >> h;
    while (s.top().first < h)
    {
      s.pop();
    }
    cout << s.top().second << " ";
    s.push({h, i});
  }

  return 0;
}