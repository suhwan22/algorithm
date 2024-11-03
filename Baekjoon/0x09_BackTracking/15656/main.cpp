#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[7];
vector<int> v;

void func(int n, int m)
{
  if ((int)v.size() == m)
  {
    for (int i = 0; i < m; i++)
      cout << v[i] << " ";
    cout << "\n";
    return ;
  }
  for (int i = 0; i < n; i++)
  {
    v.push_back(arr[i]);
    func(n, m);
    v.pop_back();
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  func(n, m);

  return 0;
}