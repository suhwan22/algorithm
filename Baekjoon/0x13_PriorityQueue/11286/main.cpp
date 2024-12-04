#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  int input;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  while (n--)
  {
    cin >> input;
    if (input == 0)
    {
      if (pq.empty())
        cout << "0\n";
      else
      {
        cout << pq.top().second << "\n";
        pq.pop();
      }
    }
    else
      pq.push({abs(input), input});
  }

  return 0;
}