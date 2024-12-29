#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

// n x n 
int n;

// 인구수
int po[21][21] = {};

// 선거구
int area[21][21] = {};

void setArea(int d1, int d2, int x, int y);
int calPo();

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> po[i][j];
	}
	int min = 2147483647;
	for (int d1 = 1; d1 <= 20; d1++)
	{
		for (int d2 = 1; d2 <= 20; d2++)
		{
			for (int x = 1; x <= 20; x++)
			{
				for (int y = 1; y <= 20; y++)
				{
					if (!(x < x + d1 + d2) || !(x + d1 + d2 <= n) || !(1 <= y - d1)
						|| !(y - d1 < y) || !(y < y + d2) || !(y + d2 <= n))
						continue;
						bzero(area, sizeof(area));
						setArea(d1, d2, x, y);
						int dif = calPo();
						if (min > dif)
							min = dif;
				}
			}
		}
	}
	cout << min;

	return 0;
}

void setArea(int d1, int d2, int x, int y)
{
	for (int i = x, j = y; i <= x + d1; i++, j--)
	{
		for (int k = i; k <= n; k++)
			area[k][j] = 5;
	}
	for (int i = x, j = y; i <= x + d2; i++, j++)
	{
		for (int k = i; k <= n; k++)
			area[k][j] = 5;
	}
	for (int i = x + d1, j = y - d1; i <= x + d1 + d2; i++, j++)
	{
		for (int k = i + 1; k <= n; k++)
			area[k][j] = 0;
	}
	for (int i = x + d2, j = y + d2; i <= x + d1 + d2; i++, j--)
	{
		for (int k = i + 1; k <= n; k++)
			area[k][j] = 0;
	}

	for (int i = 1; i < x + d1; i++)
	{
		for (int j = 1; j <= y; j++)
		{
			if (area[i][j] == 5) break;
				area[i][j] = 1;
		}
	}
	for (int i = 1; i <= x + d2; i++)
	{
		for (int j = y + 1; j <= n; j++)
		{
			if (area[i][j] == 5) continue;
				area[i][j] = 2;
		}
	}
	for (int i = x + d1; i <= n; i++)
	{
		for (int j = 1; j < y - d1 + d2; j++)
		{
			if (area[i][j] == 5) break;
				area[i][j] = 3;
		}
	}
	for (int i = x + d2 + 1; i <= n; i++)
	{
		for (int j = y - d1 + d2; j <= n; j++)
		{
			if (area[i][j] == 5) continue;
				area[i][j] = 4;
		}
	}
}

int calPo()
{
	int sum[6] = {};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			sum[area[i][j]] += po[i][j];
	}
	sort(sum, sum + 6);

	return sum[5] - sum[1];
}