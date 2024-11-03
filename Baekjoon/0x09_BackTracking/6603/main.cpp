#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  int input;
  while (1)
  {
    cin >> n;
    if (n == 0)
      break;
    vector<int> arr;
    vector<int> seq;
    for (int i = 0; i < n; i++)
    {
      cin >> input;
      arr.push_back(input);
      if (i < 6)
        seq.push_back(0);
      else
        seq.push_back(1);
    }
    do
    {
      for (int i = 0; i < n; i++)
      {
        if (seq[i] == 0)
          cout << arr[i] << " ";
      }
      cout << "\n";
    } while (next_permutation(seq.begin(), seq.end()));
    cout << "\n";
  }

  return 0;
}