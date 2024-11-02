#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;

stack<int> p[3];
queue<pair<int, int>> output;
int cnt = 0;

void cal(int n, int s, int d)
{
  cnt++;
  if (n == 1)
  {
    output.push({s + 1, d + 1});
    p[d].push(p[s].top());
    p[s].pop();
    return ;
  }
  cal(n - 1, s, 3 - s - d);
  output.push({s + 1, d + 1});
  p[d].push(p[s].top());
  p[s].pop();
  cal(n - 1, 3 - s - d, d);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  // n은 탑의 크기
  int n;
  cin >> n;
  for (int i = n; i > 0; i--)
    p[0].push(i);

  cal(n, 0, 2);
  cout << cnt << "\n";
  while (!output.empty())
  {
    cout << output.front().first << " " << output.front().second << "\n";
    output.pop();
  }
  return 0;
}