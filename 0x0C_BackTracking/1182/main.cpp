#include <iostream>

using namespace std;

bool set[20] = {};
int arr[20];
int cnt = 0;

void func(int ans, int s, int n, int t)
{
  if (ans == s)
  {
    cnt++;
    // for (int i = 0; i < n; i++)
    // {
    //   if (set[i] == true)
    //     cout << arr[i] << " ";
    // }
    // cout << "\n";
  }
  for (int i = t; i < n; i++)
  {
    if (set[i] == false)
    {
      set[i] = true;
      func(ans + arr[i], s, n, i);
      set[i] = false;
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, s;
  cin >> n >> s;
  int ans;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int i = 0; i < n; i++)
  {
    ans = arr[i];
    set[i] = true;
    func(ans, s, n, i);
    set[i] = false;
  }

  cout << cnt;

  return 0;
}