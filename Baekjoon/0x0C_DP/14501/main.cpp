#include <iostream>
#include <map>

using namespace std;

// 부르트포스로 풀었다.
// DP로 푼 코드는 퇴사2#15486 에서 볼 수 있다.

pair<int, int> schedule[16] = {};
bool used[16] = {};
int n;
int max = 0;

void dfs(int idx, int sum);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> schedule[i].first >> schedule[i].second;

  for (int i = 1; i <= n; i++)
  {
    if (i + schedule[i].first > n + 1) continue;
    dfs(i, schedule[i].second);
  }

  cout << ::max;
  return 0;
}

void dfs(int idx, int sum)
{
  if (::max < sum)
    ::max = sum;
  for (int i = idx + 1; i <= n; i++)
  {
    if (i < idx + schedule[idx].first) continue;
    if (i + schedule[i].first > n + 1) continue;
    dfs(i, sum + schedule[i].second);
  }
}