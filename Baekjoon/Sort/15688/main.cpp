#include <iostream>

using namespace std;

int arr[1000001] = {};
int arr2[1000001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int idx;
  for (int i = 0; i < n; i++)
  {
    cin >> idx;
    if (idx >= 0)
      arr[idx]++;
    else
      arr2[-idx]++;
  }

  for (int i = 1000000; i > 0; i--)
  {
    for (int j = 0; j < arr2[i]; j++)
      cout << "-" << i << "\n";
  }
  for (int i = 0; i < 1000001; i++)
  {
    for (int j = 0; j < arr[i]; j++)
      cout << i << "\n";
  }

  return 0;
}