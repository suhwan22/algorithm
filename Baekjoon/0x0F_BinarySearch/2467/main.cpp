#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int pos[100000] = {};
int neg[100000] = {};
int pCnt = 0, nCnt = 0;

int bSearch(int target);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    if (input >= 0)
      pos[pCnt++] = input;
    else
      neg[nCnt++] = input;
  }

  sort(pos, pos + pCnt);
  pos[pCnt] = -2147483648;
  sort(neg, neg + nCnt);
  int a, b, min = 2147483647;
  if (pCnt == 0)
  {
    cout << neg[nCnt - 2] << " " << neg[nCnt - 1];
    return 0;
  }
  if (pCnt == 1 && nCnt > 1)
  {
    for (int i = 0; i < nCnt; i++)
    {
      if (abs(neg[i] + pos[0]) < min)
      {
        a = neg[i];
        b = pos[0];
        min = abs(a+b);
      }
    }
    if (abs(neg[nCnt - 2] + neg[nCnt - 1]) < min)
      cout << neg[nCnt - 2] << " " << neg[nCnt - 1];
    else
      cout << a << " " << b;
    return 0;
  }
  for (int i = 0; i < nCnt; i++)
  {
    int temp = bSearch(abs(neg[i]));
    if (abs(neg[i] + temp) < min)
    {
      a = neg[i];
      b = temp;
      min = abs(a + b);
    }
  }
  if (pCnt > 1 && pos[0] + pos[1] < min)
  {
    a = pos[0];
    b = pos[1];
  }
  cout << a << " " << b;

  return 0;
}

int bSearch(int target)
{
  int st = 0;
  int en = pCnt;
  while (st < en)
  {
    int mid = (st + en) / 2;
    if (mid == st)
    {
      if (en != pCnt)
        return abs(target - pos[st]) >= abs(target - pos[en]) ? pos[en] : pos[st];
      else
        return pos[mid];
    }
    else
    {
      if (target < pos[mid])
        en = mid;
      else if (target > pos[mid])
        st = mid;
      else if (target == pos[mid])
        return pos[mid];
    }
  }
  return 0;
}