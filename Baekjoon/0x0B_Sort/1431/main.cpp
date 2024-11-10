#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const string &a, const string &b)
{
  if (a.length() != b.length())
    return a.length() < b.length();
  int aSum = 0, bSum = 0;
  for (char c : a)
  {
    if (isdigit(c))
      aSum += c - '0';
  }
  for (char c : b)
  {
    if (isdigit(c))
      bSum += c - '0';
  }
  if (aSum != bSum)
    return aSum < bSum;
  return a < b;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<string> arr;

  string input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    arr.push_back(input);
  }

  sort(arr.begin(), arr.end(), comp);
  for (string str : arr)
    cout << str << "\n";

  return 0;
}