#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int input[1000000] = {};
vector<int> arr;
vector<int> idx;
int n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> input[i];

  for (int i = 0; i < n; i++)
  {
    auto it = lower_bound(arr.begin(), arr.end(), input[i]);
    if (it == arr.end())
    {
      idx.push_back(arr.size());
      arr.push_back(input[i]);
    }
    else
    {
      idx.push_back(it - arr.begin());
      arr[it - arr.begin()] = input[i];
    }
  }
  cout << arr.size() << "\n";
  int index = arr.size() - 1;
  vector<int> output;
  for (int i = n - 1; i >= 0; i--)
  {
    if (idx[i] == index)
    {
      output.push_back(input[i]);
      index--;
    }
    if (index < 0)
      break;
  }
  for (int i = output.size() - 1; i >= 0; i--)
    cout << output[i] << " ";

  return 0;
}