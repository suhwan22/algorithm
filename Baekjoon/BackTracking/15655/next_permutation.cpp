#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  int arr[8];
  int set[8] = {};

  
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);

  for (int i = m; i < n; i++)
    set[i] = 1;

  do
  {
    for (int i = 0; i < n; i++)
    {
      if (set[i] == 0)
        cout << arr[i] << " ";
    }
    cout << "\n";
  } while (next_permutation(set, set + n));
  

  return 0;
}