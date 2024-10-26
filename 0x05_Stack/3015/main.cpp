#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<pair<long long, long long>> s;
  long long h;
  long long cnt = 0;
  long long m = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> h;
    m = 1;
    if (!s.empty())
    {
      if (s.top().first < h)
      {
        while (!s.empty() && s.top().first < h)
        {
          cnt += s.top().second;
          s.pop();
        }
        if (!s.empty() && s.top().first == h)
        {
          cnt += s.top().second + (s.size() > 1 ? 1 : 0);
          m = s.top().second + 1;
          s.pop();
        }
        else if (!s.empty())
          cnt++;
        s.push({h, m});
      }
      else if (s.top().first == h)
      {
        cnt += s.top().second + (s.size() > 1 ? 1 : 0);
        m = s.top().second + 1;
        s.pop();
        s.push({h, m});
      }
      else
      {
        cnt++;
        s.push({h, m});
      }
    }
    else
      s.push({h, 1});
  }

  cout << cnt;

  return 0;
}