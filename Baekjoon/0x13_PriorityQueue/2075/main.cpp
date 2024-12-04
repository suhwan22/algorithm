#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  int input;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> input;
      pq.push(input);
      if ((int)pq.size() > n)
        pq.pop();
    }
  }
  cout << pq.top();

  return 0;
}