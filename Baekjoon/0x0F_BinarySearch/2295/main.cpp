#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
vector<int> two;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // 5 <= n <= 1,000
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    // 1 <= input <= 200,000,000
    arr.push_back(input);
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
      two.push_back(arr[i] + arr[j]);
  }

  sort(two.begin(), two.end());

  for (int i = n - 1; i > 0; i--)
  {
    for (int j = 0; j < n - 1; j++)
    {
      if (binary_search(two.begin(), two.end(), arr[i] - arr[j]))
      {
        cout << arr[i];
        return 0;
      }
    }
  }

  return 0;
}