#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  set<int> s;
  int input;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    s.insert(input);
  }
  vector<int> arr;
  for (auto e : s)
  {
    for (int i = 0; i < m; i++)
      arr.push_back(e);
  }

  do
  {
    reverse(arr.begin() + m, arr.end());
    for (int i = 0; i < m; i++)
      cout << arr[i] << " ";
    cout << "\n";
  } while (next_permutation(arr.begin(), arr.end()));
  

  return 0;
}