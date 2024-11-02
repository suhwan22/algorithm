#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  stack<char> s;
  string input;
  while (t--)
  {
    cin >> input;
    for (int i = 0; i < (int)input.length(); i++)
    {
      if (input.at(i) == ')')
      {
        if (!s.empty() && s.top() == '(')
          s.pop();
        else
          s.push(input.at(i));
      }
      else
        s.push(input.at(i));
    }
    if (s.empty())
      cout << "YES\n";
    else
    {
      cout << "NO\n";
      while (!s.empty())
        s.pop();
    }
  }
  
  return 0;
}