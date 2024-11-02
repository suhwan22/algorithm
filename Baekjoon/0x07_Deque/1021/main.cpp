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
  int m;

  // 0 1 2 3 4 5 6
  //   5 4 3 2 1
  // b         f


  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    pushBack(i);
  }

  int s, k;
  int cnt = 0;
  cin >> m;
  int t;

  while (m--)
  {
    cin >> t;
    for (s = 0; f - s != b; s++)
    {
      if (arr[f - s] == t)
        break ;
    }
    for (k = 0; b + k + 1 != f; k++)
    {
      if (arr[b + k + 1] == t)
        break ;
    }
    if (s < k + 1)
    {
      for (int i = 0; i < s; i++)
        pushBack(popFront());
      popFront();
      cnt += s;
    }
    else
    {
      for (int i = 0; i <= k; i++)
        pushFront(popBack());
      popFront();
      cnt += k + 1;
    }
  }

  cout << cnt;

  return 0;
}