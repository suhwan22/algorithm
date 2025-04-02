/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-6549
 * Created     : 2025-04-02 19:50:22
 * Updated     : 2025-04-02 21:26:26
 */

#include <iostream>
#include <stack>
#include <map>

using namespace std;

int n;
stack<pair<long long, int>> s;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
  while (1)
  {
    cin >> n;
    long long h, ans = 0;
    if (n == 0)
      break;
    for (int i = 0; i <= n; i++)
    {
      if (i < n)
        cin >> h;
      pair<long long, int> cur = {0, i};
      while (!s.empty() && (i == n || h < s.top().first))
      {
        cur = s.top();
        s.pop();
        if (ans < cur.first * (i - cur.second))
          ans = cur.first * (i - cur.second);
      }
      if (i != n && h != 0 && (s.empty() || s.top().first < h))
        s.push({h, cur.second});
    }
    cout << ans << "\n";
  }

	return 0;
}
