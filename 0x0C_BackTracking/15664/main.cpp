#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> arr;
  vector<int> seq;

  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
    if (i < m)
      seq.push_back(0);
    else
      seq.push_back(1);
  }

  sort(arr.begin(), arr.end());
  set<vector<int>> us;

  do
  {
    vector<int> output;
    for (int i = 0; i < n; i++)
    {
      if (seq[i] == 0)
        output.push_back(arr[i]);
    }
    us.insert(output);
  } while (next_permutation(seq.begin(), seq.end()));
  for (auto e : us)
  {
    for (int i = 0; i < (int)e.size(); i++)
      cout << e[i] << " ";
    cout << "\n";
  }

  return 0;
}