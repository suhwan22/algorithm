#include <iostream>
#include <algorithm>

using namespace std;

int n;
int seq[9] = {};
int board[50][9] = {};

int play();

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 9; j++)
      cin >> board[i][j]; 
  }
  for (int i = 0; i < 9; i++)
    seq[i] = i;

  int max = 0;
  do
  {
    if (seq[3] != 0)
      continue;
    int score = play();
    max = score > max ? score : max;
  } while (next_permutation(seq, seq + 9));

  cout << max;

  return 0;
}

int play()
{
  char base = 0;
  int score = 0;
  int out = 0;
  int j = 0;
  for (int i = 0; i < n; i++)
  {
    base = 0;
    out = 0;
    while (1)
    {
      if (board[i][seq[j]] == 0)
        out++;
      else
      {
        base |= 0b00000001;
        for (int k = 0; k < board[i][seq[j]]; k++)
        {
          base <<= 1;
          if (base & 0b00010000)
          {
            score++;
            base &= 0b00001111;
          }
        }
      }
      if (++j >= 9)
        j = 0;
      if (out >= 3)
        break;
    }
  }
  return score;
}