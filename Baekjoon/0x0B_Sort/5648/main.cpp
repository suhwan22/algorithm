#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  vector<long long> arr;

  long long input;
  for (int i = 0; i < n; i++)
  {
    long long temp = 0;
    cin >> input;
    while (input)
    {
      temp *= 10;
      temp += input % 10;
      input /= 10;
    }
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());
  for (long long ll : arr)
    cout << ll << "\n";

  return 0;
}