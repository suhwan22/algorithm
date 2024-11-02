#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  map<int, int> m;

  int n;
  cin >> n;

  int input;
  int cnt = 0;

  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    cin >> input;
    v.push_back(input);
  }

  int x;

  cin >> x;

  for (int i = 0; i < n; i++)
  {
    if (m[x - v[i]])
      cnt++;
    m[v[i]] = 1;
  }

  cout << cnt;

  return 0;
}