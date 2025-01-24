#include <iostream>

using namespace std;

int n;
int board[101] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	
	int cnt = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		while (board[i+1] <= board[i])
		{
			cnt++;
			board[i]--;
		}
	}
	cout << cnt;

	return 0;
}
