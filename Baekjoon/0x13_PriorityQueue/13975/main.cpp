#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n, t;
  cin >> t;
  while (t--)
  {
    cin >> n;
    long long input;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
      cin >> input;
      pq.push(input);
    }
    long long a, b;
    long long ans = 0;
    while (pq.size() > 1)
    {
      a = pq.top();
      pq.pop();
      b = pq.top();
      pq.pop();
      ans += a + b;
      pq.push(a + b);
    }
    cout << ans << "\n";
  }

  return 0;
}