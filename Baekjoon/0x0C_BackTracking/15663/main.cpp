#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  int input;
  for (int i = 0; i < n;i ++)
  {
    cin >> input;
    arr.push_back(input);
  }

  sort(arr.begin(), arr.end());
  vector<vector<int>> output;
  int cnt = 0;

  do
  {
    reverse(arr.begin() + m, arr.end());
    vector<int> temp;
    for (int i = 0; i < m; i++)
      temp.push_back(arr[i]);
    if (cnt != 0 && equal(output[cnt - 1].begin(), output[cnt - 1].end(), temp.begin())) continue;
    output.push_back(temp);
    cnt++;
  } while (next_permutation(arr.begin(), arr.end()));

  for (int i = 0; i < (int)output.size(); i++)
  {
    for (int j = 0; j < (int)output[i].size(); j++)
      cout << output[i][j] << " ";
    cout << "\n";
  }

  return 0;
}