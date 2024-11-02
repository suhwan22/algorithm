#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n;
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
  }

  sort(arr.begin(), arr.end());

  cin >> m;
  while (m--)
  {
    cin >> input;
    int st = 0, en = arr.size() - 1;
    int mid;
    bool flag = true;
    while (st <= en)
    {
      mid = (st + en) / 2;
      if (arr[mid] < input)
        st = mid + 1;
      else if (arr[mid] > input)
        en = mid - 1;
      else
      {
        cout << "1\n";
        flag = false;
        break;
      }
    }
    if (flag)
      cout << "0\n";
  }

  return 0;
}