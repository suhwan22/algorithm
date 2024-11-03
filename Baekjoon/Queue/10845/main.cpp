#include <iostream>

using namespace std;

int q[10001];
int f = 10000;
int b = 10000;

int size()
{
  return f - b;
}

bool empty()
{
  if (size() == 0)
    return true;
  return false;
}

void push(int a)
{
  q[b--] = a;
}

int pop()
{
  if (!empty())
    return q[f--];
  return -1;
}

int front()
{
  if (!empty())
    return q[f];
  return -1;
}

int back()
{
  if (!empty())
    return q[b + 1];
  return -1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 10001; i++)
    q[i] = -1;

  int n;
  cin >> n;
  string s;
  int input;
  while (n--)
  {
    cin >> s;
    if (s == "push")
    {
      cin >> input;
      push(input);
    }
    else if (s == "pop")
      cout << pop() << "\n";
    else if (s == "empty")
      cout << empty() << "\n";
    else if (s == "size")
      cout << size() << "\n";
    else if (s == "front")
      cout << front() << "\n";
    else if (s == "back")
      cout << back() << "\n";
    else
      cout << "ha?";
  }

  return 0;
}