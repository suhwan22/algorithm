#include <iostream>
#include <deque>

using namespace std;

int arr[20001];
int f = 10000;
int b = 10000;

int size()
{
  return f - b;
}

bool empty()
{
  if (size() > 0)
    return false;
  return true;
}

void pushFront(int x)
{
  arr[++f] = x;
}

void pushBack(int x)
{
  arr[b--] = x;
}

int popFront()
{
  if (!empty())
    return arr[f--];
  return -1;
}

int popBack()
{
  if (!empty())
    return arr[++b];
  return -1;
}

int front()
{
  if (!empty())
    return arr[f];
  return -1;
}

int back()
{
  if (!empty())
    return arr[b + 1];
  return -1;
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 20001; i++)
  {
    arr[i] = -1;
  }

  int n;
  cin >> n;
  string s;
  int input;
  while (n--)
  {
    cin >> s;
    if (s == "push_front")
    {
      cin >> input;
      pushFront(input);
    }
    else if (s == "push_back")
    {
      cin >> input;
      pushBack(input);
    }
    else if (s == "pop_front")
      cout << popFront() << "\n";
    else if (s == "pop_back")
      cout << popBack() << "\n";
    else if (s == "size")
      cout << size() << "\n";
    else if (s == "empty")
      cout << empty() << "\n";
    else if (s == "front")
      cout << front() << "\n";
    else if (s == "back")
      cout << back() << "\n";
  }

  return 0;
}