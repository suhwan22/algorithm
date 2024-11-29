#include <iostream>

using namespace std;

int n;
int in[100001] = {};
int post[100001] = {};
void dfs(int pSt, int pEn, int iSt, int iEn);

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> in[i];
  for (int i = 0; i < n; i++)
    cin >> post[i];

  dfs(0, n - 1, 0, n - 1);

  return 0;
}

void dfs(int pSt, int pEn, int iSt, int iEn)
{
  if (pSt > pEn || iSt > iEn) return;
  int root = post[pEn];
  cout << root << " ";
  int i = 0;
  for (;iSt + i <= iEn; i++)
    if (in[iSt+i] == root) break;
  dfs(pSt, pSt + i - 1, iSt, iSt + i - 1);
  dfs(pSt + i, pEn - 1, iSt + i + 1, iEn);
}