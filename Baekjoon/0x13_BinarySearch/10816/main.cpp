#include <iostream>
#include <vector>

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
  int minIdx, maxIdx;
  while (m--)
  {
    cin >> input;
    int st = 0, en = arr.size();
    int mid;
    while (st < en)
    {
      mid = (st + en) / 2;
      if (input <= arr[mid])
        en = mid;
      else if (input > arr[mid])
        st = mid + 1;
      if (st == en)
        break;
    }
    minIdx = st;
    st = 0;
    en = arr.size();
    while (st < en)
    {
      mid = (st + en) / 2;
      if (input < arr[mid])
        en = mid;
      else if (input >= arr[mid])
        st = mid + 1;
      if (st == en)
        break;
    }
    maxIdx = st;
    cout << maxIdx - minIdx << " ";
  }

  return 0;
}