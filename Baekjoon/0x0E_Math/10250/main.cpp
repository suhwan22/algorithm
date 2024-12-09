#include <iostream>

using namespace std;

int arr[100][100] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int h, w, t, n;
	cin >> t;
	while (t--)
	{
		cin >> h >> w >> n;
		n--;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				arr[i][j] = 100 * (i + 1) + j + 1 ;
			}
		}
		cout << arr[n%h][n/h] << "\n";
	}

	return 0;
}
