#include <iostream>

using namespace std;

int a, b;
int arr[1001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int idx = 1, k = 1;
	while (idx <= 1000)
	{
		for (int i = 0; i < k && idx <= 1000; i++)
			arr[idx++] = k;
		k++;
	}
	long long sum = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
		sum += arr[i];
	cout << sum;

	return 0;
}
