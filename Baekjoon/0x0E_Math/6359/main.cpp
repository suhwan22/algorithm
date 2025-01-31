#include <iostream>

using namespace std;

int t;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	int n;
	while (t--)
	{
		cin >> n;
		bool room[101] = {};
		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= n; j += i)
				room[j] = !room[j];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (room[i] == false)
				cnt++;
		cout << cnt << "\n";
	}

	return 0;
}
