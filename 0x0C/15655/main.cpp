#include <iostream>
#include <algorithm>

using namespace std;

int arr[8];
vector<int> set;

void func(int n, int m, int idx)
{
  if ((int)set.size() == m)
  {
    for (int i = 0; i < m; i++)
      cout << set[i] << " ";
    cout << "\n";
    return ;
  }
  for (int i = idx; i < n; i++)
  {
    set.push_back(arr[i]);
    func(n, m, i + 1);
    set.pop_back();
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

  for (int i = 0; i <= n - m; i++)
  {
    set.push_back(arr[i]);
    func(n, m, i + 1);
    set.pop_back();
  }

  return 0;
}