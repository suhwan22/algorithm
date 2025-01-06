#include <iostream>

using namespace std;

int n;
int tree[100001][2];
int cnt = 0, icnt = 0;

void likeInorder(int cur);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int v, l, r;
	for (int i = 1; i <= n; i++)
	{
		cin >> v >> l >> r;
		tree[v][0] = l;
		tree[v][1] = r;
	}
	likeInorder(1);
	cout << cnt - 1;

	return 0;
}

void likeInorder(int cur)
{
	cnt++;
	if (tree[cur][0] != -1)
	{
		likeInorder(tree[cur][0]);
		cnt++;
	}
	icnt++;
	if (tree[cur][1] != -1)
	{
		likeInorder(tree[cur][1]);
		if (icnt != n)
			cnt++;
	}
}