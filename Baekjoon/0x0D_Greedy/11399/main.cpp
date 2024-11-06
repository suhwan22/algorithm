#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000] = {};
int sum[1000] = {};

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  sort(arr, arr + n);
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i] * (n - i);
  cout << sum;
}