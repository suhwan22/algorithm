#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  unordered_set<string> hs;
  int n;
  cin >> n;
  string a, b;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    if (b == "enter")
      hs.insert(a);
    else
      hs.erase(a);
  }

  vector<string> output(hs.begin(), hs.end());
  sort(output.begin(), output.end(), greater<string>());
  for (string o : output)
    cout << o << "\n";

  return 0;
}