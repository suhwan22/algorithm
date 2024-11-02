#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;

  cin >> n;

  list<char> str;
  list<char>::iterator cursor;

  string input;

  while (n--)
  {
    str.clear();
    cursor = str.end();
    cin >> input;
    for (int i = 0; i < input.length(); i++)
    {
      if (input[i] == '<')
      {
        if (cursor != str.begin())
          cursor--;
      }
      else if (input[i] == '>')
      {
        if (cursor != str.end())
          cursor++;
      }
      else if (input[i] == '-')
      {
        if (cursor != str.begin())
          cursor = str.erase(prev(cursor, 1), cursor);
      }
      else
      {
        str.insert(cursor, input[i]);
      }
    }
    for (list<char>::iterator it = str.begin(); it != str.end(); it++)
    {
      cout << *it;
    }
    cout << "\n";
  }

  return 0;
}