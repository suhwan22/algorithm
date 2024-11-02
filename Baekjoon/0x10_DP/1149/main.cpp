#include <iostream>

using namespace std; 

typedef struct trio
{
  int r;
  int g;
  int b;
} trio;

trio rgb[1001];

// 지금 b 칠하는게 제일 싸
// 그러면 이전에 r g 칠했던거 중에 제일 싼거 고르면 됨
// d[n][b] = min(d[n-1][r], d[n-1][g])
// d[1][r], d[1][g], d[1][b]
// d[2][b] -> min(d[1][r], d[1][g]) + rgb[2].b

//d[n][r] = min(d[n-1][b], d[n-1][g]) + rgb[n].r

int d[1001][3] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++)
  {
    cin >> rgb[i].r;
    cin >> rgb[i].g;
    cin >> rgb[i].b;
  }

  // for (int i = 1; i <= n; i++)
  // {
  //   cout << "rgb[" << i << "]: " << rgb[i].r << " " << rgb[i].g << " " << rgb[i].b << "\n";
  // }

  // r: 0, g: 1, b: 2
  d[1][0] = rgb[1].r;
  d[1][1] = rgb[1].g;
  d[1][2] = rgb[1].b;

  for (int i = 2; i <= n; i++)
  {
    d[i][0] = min(d[i - 1][1], d[i - 1][2]) + rgb[i].r;
    d[i][1] = min(d[i - 1][0], d[i - 1][2]) + rgb[i].g;
    d[i][2] = min(d[i - 1][1], d[i - 1][0]) + rgb[i].b;
  }

  cout << min(min(d[n][0], d[n][1]), d[n][2]);

  return 0;
}
