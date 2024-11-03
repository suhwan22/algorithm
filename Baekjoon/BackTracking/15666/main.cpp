#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> output;


int n, m;

void dfs(int idx, int remain);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  set<int> s;
  cin >> n >> m;
  int input;
  for (int i = 0 ; i < n; i++)
  {
    cin >> input;
    s.insert(input);
  }

  for (auto e : s)
  {
    arr.push_back(e);
  }

  dfs(0, m);

  return 0;
}

void dfs(int idx, int remain)
{
  if (remain == 0)
  {
    for (int i = 0; i < m; i++)
      cout << output[i] << " ";
    cout << "\n";
    return ;
  }
  for (int i = idx; i < (int)arr.size(); i++)
  {
    output.push_back(arr[i]);
    dfs(i, remain - 1);
    output.pop_back();
  }
}