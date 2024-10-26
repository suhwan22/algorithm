#include <iostream>
#include <string>

using namespace std;

bool isStrfry(string a, string b)
{
  if (a.length() != b.length())
    return false;

  int arr[26] = {};

  for (int i = 0; i < a.length(); i++)
  {
    arr[a[i] - 'a']++;
    arr[b[i] - 'a']--;
  }

  for (int i = 0; i < 26; i++)
  {
    if (arr[i] != 0)
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  string a, b;

  while (n--)
  {
    cin >> a >> b;
    if (isStrfry(a, b))
      cout << "Possible\n";
    else
      cout << "Impossible\n";
  }

  return 0;
}