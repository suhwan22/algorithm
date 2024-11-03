#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  queue<int> q;
  int a;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    q.push(a);
  }

  stack<int> s;
  string ans = "";
  int k = 1;
  while (!q.empty())
  {
    if (s.empty())
    {
      ans.append("+");
      s.push(k);
      k++;
    }
    else if (s.top() == q.front())
    {
      ans.append("-");
      q.pop();
      s.pop();
    }
    else
    {
      if (k > n)
        break ;
      ans.append("+");
      s.push(k);
      k++;
    }
  }
  if (q.empty())
  {
    for (int i = 0; i < ans.length(); i++)
      cout << ans[i] << "\n";
  }
  else
    cout << "NO\n";

  return 0;
}