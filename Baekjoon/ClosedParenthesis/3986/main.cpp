#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  stack<char> s;
  string input;
  int cnt = 0;

  while (n--)
  {
    cin >> input;
    for(int i = 0; i < (int)input.length(); i++)
    {
      if (input.at(i) == 'A')
      {
        if (!s.empty() && s.top() == 'A')
          s.pop();
        else
          s.push(input.at(i));
      }
      else if (input.at(i) == 'B')
      {
        if (!s.empty() && s.top() == 'B')
          s.pop();
        else
          s.push(input.at(i));
      }
    }
    if (s.empty())
      cnt++;
    else
    {
      while(!s.empty())
        s.pop();
    }
  }
  cout << cnt;
  return 0;
}