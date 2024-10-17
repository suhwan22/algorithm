#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
long long n, m;

long long calWire(long long len);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
  }

  long long st = 1;
  long long en = 2147483647;
  long long mid;

  // st mid en
  // 1  2   4
  // too much
  // 3  3   4
  // 
  // st == mid 가 될때 처리를 잘해야함

  while (st < en)
  {
    mid = (st + en) / 2;
    if (st == mid)
    {
      if (calWire(en) >= m)
        st = en;
      else
        en = st;
    }
    else
    {
      if (calWire(mid) < m)
        en = mid - 1;
      else
        st = mid;
    }
  }
  if (calWire(st) >= m)
    cout << st;
  else
    cout << 0;

  return 0;
}

long long calWire(long long len)
{
  long long cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += arr[i] / len;
  return cnt;
}