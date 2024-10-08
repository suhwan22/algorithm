#include <iostream>

using namespace std;

int arr[1000];

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int temp;
  
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << "\n";

  return 0;
}