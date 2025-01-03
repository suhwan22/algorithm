#include <iostream>

using namespace std;

int n;
int arr[100001] = {};
bool used[100001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	long long st = 0, en = 0;
	long long cnt = 0;
	while (en < n)
	{
		if (used[arr[en]] == true)
		{
			while (used[arr[en]] == true)
			{
				cnt += en - st;
				used[arr[st++]] = false;
			}
		}
		else
			used[arr[en++]] = true;
	}
	cnt += (en - st) * (1 + en - st) / 2;
	cout << cnt;

	return 0;
}
