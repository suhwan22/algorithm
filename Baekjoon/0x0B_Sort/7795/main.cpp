#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arrA[20000] = {};
int arrB[20000] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  int n, m;
  while (t--)
  {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
      cin >> arrA[i];
    for (int i = 0; i < m; i++)
      cin >> arrB[i];
    sort(arrA, arrA + n);
    sort(arrB, arrB + m);
    int a = 0, b = 0, sum = 0;
    while (a < n && b < m)
    {
      if (arrA[a] > arrB[b])
        b++;
      else
      {
        sum += b;
        a++;
      }
    }
    while (a++ < n)
      sum += b;
    cout << sum << "\n";
  }

  return 0;
}