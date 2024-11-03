#include <iostream>
#include <algorithm>

using namespace std;

int a[50]={};
int b[50]={};

bool comp(int a, int b)
{
  return a > b;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int i = 0; i < n; i++)
    cin >> b[i];

  sort(b, b + n);
  sort(a, a + n, comp);

  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += a[i] * b[i];

  cout << sum;

  return 0;
}