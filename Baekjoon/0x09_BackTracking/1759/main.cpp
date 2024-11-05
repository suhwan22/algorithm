#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool consonant[15] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  char input;
  vector<char> str;
  vector<int> seq;
  for (int i = 0; i < m; i++)
  {
    cin >> input;
    str.push_back(input);
    if (i < n)
      seq.push_back(0);
    else
      seq.push_back(1);
  }

  sort(str.begin(), str.end());

  for (int i = 0; i < m; i++)
  {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'i' || str[i] == 'u')
      consonant[i] = true;
  }

  do
  {
    int cNum = 0;
    string output;
    for (int i = 0; i < m; i++)
    {
      if (seq[i] == 0)
      {
        output.push_back(str[i]);
        if (consonant[i] == true)
          cNum++;
      }
    }
    if (cNum > 0 && n - cNum > 1)
      cout << output << "\n";
  } while (next_permutation(seq.begin(), seq.end()));

  return 0;
}