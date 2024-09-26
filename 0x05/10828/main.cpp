#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;

  int n;
  cin >> n;

  string input;
  int m;

  while (n--)
  {
    cin >> input;
    if (input == "push")
    {
      cin >> m;
      s.push(m);
    }
    else if (input == "pop")
    {
      if (s.empty())
        cout << -1 << "\n";
      else
      {
        cout << s.top() << "\n";
        s.pop();
      }
    }
    else if (input == "top")
    {
      if (s.empty())
        cout << -1 << "\n";
      else
        cout << s.top() << "\n";
    }
    else if (input == "size")
    {
      cout << s.size() << "\n";
    }
    else if (input == "empty")
    {
      cout << s.empty() << "\n";
    }
    else
    {
      return 1;
    }
  }

  return 0;
}