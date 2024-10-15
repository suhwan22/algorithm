#include <iostream>

using namespace std;

int D[1001] = {};


int arr[1001] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // 1 <= n <= 1000
  // 1 <= arr[i] <= 1000

  for (int i = 0; i < n; i++)
    cin >> arr[i];
  if (n == 1)
  {
    cout << 1;
    return 0;
  }

  D[0] = 1;
  int output = 0;
  int max;
  for (int i = 1; i < n; i++)
  {
    max = 0;
    for (int j = i - 1; j >= 0; j--)
    {
      if (arr[i] > arr[j] && D[j] > max)
        max = D[j]; 
    }
    D[i] = max + 1;
    if (output < D[i])
      output = D[i];
  }
  cout << output;

  return 0;
}