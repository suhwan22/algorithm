#include <iostream>
#include <stack>

using namespace std;

long long cntEqaulElements(stack<int> s, int h)
{
  long long cnt = 0;
  while (!s.empty() && s.top() == h)
  {
    cnt++;
    s.pop();
  }
  if (!s.empty())
    cnt++;

  return cnt;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<int> s;
  long long h;
  long long cnt = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> h;
    if (!s.empty())
    {
      if (s.top() < h)
      {
        while (!s.empty() && s.top() < h)
        {
          cnt++;
          s.pop();
        }
        cnt += cntEqaulElements(s, h);
        s.push(h);
      }
      else if (s.top() == h)
      {
        cnt += cntEqaulElements(s, h);
        s.push(h);
      }
      else
      {
        cnt++;
        s.push(h);
      }
    }
    else
      s.push(h);
    // cout << "input(" << h << "), current cnt:" << cnt << "\n";
  }

  cout << cnt;

  return 0;
}