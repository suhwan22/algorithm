#include <iostream>

using namespace std;

int n, k;
int coin[100] = {};
int D[10001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	D[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int v = coin[i]; v <= k; v++)
			D[v] += D[v - coin[i]];
	}
	cout << D[k];

	return 0;
}
