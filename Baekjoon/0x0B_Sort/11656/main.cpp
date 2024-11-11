#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a;
  cin >> a;

  vector<string> arr;
  for (int i = 0; i < (int)a.length(); i++)
  {
    string temp = a.substr(i, a.length() - i);
    arr.push_back(temp);
  }

  sort(arr.begin(), arr.end());

  for (string str : arr)
    cout << str << "\n";

  return 0;
}