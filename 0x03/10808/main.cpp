#include <iostream>
#include <string>

using namespace std;

int main()
{
  int a[26];

  for (int i = 0; i < 26; i++)
    a[i] = 0;
  
  string s;

  cin >> s;

  for (int i = 0; i < s.length(); i++)
    a[s[i] - 'a'] += 1;

  for (int i = 0; i < 26; i++)
    cout << a[i] << " ";

    return 0;
}