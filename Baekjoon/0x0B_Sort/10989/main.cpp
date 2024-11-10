#include <iostream>

using namespace std;

int main()
{
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int arr[10001] = {};
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[num]++;
	}
	for (int j = 1; j <= 10000; j++)
	{
		if(arr[j] != 0)
			for (int s = 0; s < arr[j]; s++)
				cout << j << "\n";
	}
	return 0;
}