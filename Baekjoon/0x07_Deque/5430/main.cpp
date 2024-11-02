#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int arr[200001];
int f = 100000;
int b = 100000;

int dir = +1;

int size()
{
  return abs(f - b);
}

bool empty()
{
  if (size() > 0)
    return false;
  return true;
}

void pushFront(int x)
{
  f += dir;
  arr[f] = x;
}

void pushBack(int x)
{
  arr[b] = x;
  b += -1 * dir;
}

int popFront()
{
  int temp;
  if (!empty())
  {
    temp = arr[f];
    f += -1 * dir;
    return temp;
  }
  return -1;
}

int popBack()
{
  if (!empty())
  {
    b += dir;
    return arr[b];
  }
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
    return arr[b + dir];
  return -1;
}

void rotate()
{
  int temp;
  temp = b;
  b = f + dir;
  f = temp + dir;
  dir *= -1;
}

void printArr()
{
  cout << "[";
  for (; !empty();)
  {
    cout << popFront();
    if (!empty())
      cout << ",";
  }
  cout << "]\n";
}

int run(string p)
{
  while (p.length())
  {
    if (p.at(0) == 'R')
    {
      rotate();
    }
    else if(p.at(0) == 'D')
    {
      if (popFront() == -1)
        return -1;
    }
    p.erase(p.begin());
  }
  return 0;
}

void setArr(string s, int n)
{
  int a;
  char c;
  s.erase(s.begin());
  stringstream ss(s);
  while (n--)
  {
    ss >> a >> c;
    pushBack(a);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  string p;
  string s;
  int n;
  cin >> t;
  while(t--)
  {
    cin >> p; //RDD
    cin >> n; //배열 크기
    cin >> s; //배열 원소
    f = 100001;
    b = 100001;
    dir = 1;
    setArr(s, n);
    if (run(p) == -1)
      cout << "error\n";
    else
      printArr();
  }

  return 0;
}