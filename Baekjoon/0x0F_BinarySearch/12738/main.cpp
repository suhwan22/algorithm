#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    if (arr.empty())
      arr.push_back(input);
    else
    {
      auto it = lower_bound(arr.begin(), arr.end(), input);
      if (it == arr.end())
        arr.push_back(input);
      else
        arr[it - arr.begin()] = input;
    }
  }
  cout << arr.size();

  return 0;
}