#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a;
  cin >> a;

  int arr[10] = {};

  arr[a % 10] += 1;

  while (a / 10)
  {
    a /= 10;
    arr[a % 10] += 1;
  }

  int max = (arr[6] + arr[9]) % 2 == 0 ? (arr[6] + arr[9]) / 2 : (arr[6] + arr[9]) / 2 + 1;

  for (int i = 0; i < 10; i++)
  {
    if (i != 6 && i != 9 && max < arr[i])
      max = arr[i];
  }

  cout << max;

  return 0;
}