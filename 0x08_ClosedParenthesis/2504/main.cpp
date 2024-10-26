#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> s)
{
  for (;!s.empty();s.pop())
    cout << s.top() << " ";
  cout << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  stack<int> s;

  string input;

  cin >> input;
  int temp = 0;
  // -1 == (, -2 == [

  for (int i = 0; i < (int)input.length(); i++)
  {
    if (input.at(i) == ')')
    {
      if (!s.empty() && s.top() == -1)
      {
        temp = 2;
        s.pop();
        while (!s.empty() && s.top() != -1 && s.top() != -2)
        {
          temp += s.top();
          s.pop();
        }
        s.push(temp);
      }
      else if (!s.empty() && s.top() != -2)
      {
        temp = 2 * s.top();
        s.pop();
        if (!s.empty() && s.top() == -1)
          s.pop();
        else
        {
          cout << 0;
          return 0;
        }
        while (!s.empty() && s.top() != -1 && s.top() != -2)
        {
          temp += s.top();
          s.pop();
        }
        s.push(temp);
      }
      else
      {
        cout << 0;
        return 0;
      }
    }
    else if (input.at(i) == ']')
    {
      if (!s.empty() && s.top() == -2)
      {
        temp = 3;
        s.pop();
        while (!s.empty() && s.top() != -1 && s.top() != -2)
        {
          temp += s.top();
          s.pop();
        }
        s.push(temp);
      }
      else if (!s.empty() && s.top() != -1)
      {
        temp = 3 * s.top();
        s.pop();
        if (!s.empty() && s.top() == -2)
          s.pop();
        else
        {
          cout << 0;
          return 0;
        }
        while (!s.empty() && s.top() != -1 && s.top() != -2)
        {
          temp += s.top();
          s.pop();
        }
        s.push(temp);
      }
      else
      {
        cout << 0;
        return 0;
      }
    }
    else if (input.at(i) == '(')
      s.push(-1);
    else if (input.at(i) == '[')
      s.push(-2);
    // printStack(s);
  }

  for (temp = 0; !s.empty(); s.pop())
  {
    if (s.top() < 0)
    {
      cout << 0;
      return 0;
    }
    temp += s.top();
  }

  cout << temp;

  return 0;
}