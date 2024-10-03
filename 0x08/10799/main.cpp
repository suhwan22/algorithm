#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  cin >> input;

  stringstream ss(input);
  string s;

  int cnt = 0, ans = 0;

  while (getline(ss, s, ')'))
  {
    if (ss.eof() || ss.fail())
      break;
    
    if (s.length() == 1)
      ans += cnt;
    else if (s.length() == 0)
    {
      ans++;
      cnt--;
    }
    else
    {
      cnt += s.length() - 1;
      ans += cnt;
    }
  }
  cout << ans;

  return 0;
}