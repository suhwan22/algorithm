#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string input;
  stack<char> s;

  while (getline(cin, input))
  {
    for (int i = 0; i < (int)input.length(); i++)
    {
      if (i == (int)input.length() - 1 && input.at(i) == '.')
      {
        if (input.length() == 1)
          return 0;
        else
        {
          if (s.empty())
            cout << "yes\n";
          else
          {
            cout << "no\n";
            while (!s.empty())
              s.pop();
          }
        }
      }
      else
      {
        if (input.at(i) == ')')
        {
          if (!s.empty() && s.top() == '(')
            s.pop();
          else
            s.push(input.at(i));
        }
        else if (input.at(i) == ']')
        {
          if (!s.empty() && s.top() == '[')
            s.pop();
          else
            s.push(input.at(i));
        }
        else if (input.at(i) == '(' || input.at(i) == '[')
          s.push(input.at(i));
      }
    }
  }

  return 0;
}