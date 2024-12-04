#include <iostream>
#include <queue>

using namespace std;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  int input;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    pq.push(input);
  }
  int a, b;
  long long ans = 0;
  while (pq.size() > 1)
  {
    a = pq.top(); pq.pop();
    b = pq.top(); pq.pop();
    ans += a + b;
    pq.push(a+b);
  }
  cout << ans;

  return 0;
}