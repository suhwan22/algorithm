#include <iostream>
#include <deque>
#include <map>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, L, i, input;
  cin >> N >> L;

  deque<pair<int, int>> dq;

  for (i = 0; i < N; i++)
  {
    cin >> input;
    if (!dq.empty() && i - dq.front().second >= L)
      dq.pop_front();
    while (!dq.empty() && dq.back().first > input)
      dq.pop_back();
    dq.push_back({input, i});
    cout << dq.front().first << " ";
  }
  return 0;
}