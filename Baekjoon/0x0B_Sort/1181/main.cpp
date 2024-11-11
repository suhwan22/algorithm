#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

class Comp
{
  public:
    bool operator() (const string &a, const string &b) const
    {
      if (a.length() != b.length())
        return a.length() < b.length();
      return a < b;
    }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  set<string, Comp> s;
  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    s.insert(input);
  }

  for (string str : s)
    cout << str << "\n";

  return 0;
}