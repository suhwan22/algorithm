#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  int input;
  stack<int> s;

  while (n--)
  {
    cin >> input;
    if (input == 0)
      s.pop();
    else
      s.push(input);
  }

  int sum = 0;
  for (;s.size();)
  {
    sum += s.top();
    s.pop();
  }

  cout << sum;

  return 0;
}