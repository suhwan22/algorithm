#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  int arr[10];

  for (int i = 0; i < 10; i++)
  {
    arr[i] = 0;
  }

  cin >> a >> b >> c;

  int mul = a * b * c;

  arr[mul % 10] += 1;

  while (mul / 10)
  {
    mul /= 10;
    arr[mul % 10] += 1;
  }

  for (int i = 0; i < 10; i++)
    cout << arr[i] << "\n";

  return 0;
}