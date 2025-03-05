/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-11726
 * Created     : 2025-02-06 00:30:54
 * Updated     : 2025-03-05 19:22:49
 */

#include <iostream>

using namespace std;

int d[1001];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  d[1] = 1;
  d[2] = 2;
  for (int i = 3; i <= n; i++)
    d[i] = (d[i-1]+d[i-2])%10007;
  cout << d[n];

  return 0;
}
