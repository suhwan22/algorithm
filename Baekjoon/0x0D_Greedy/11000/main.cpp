#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
pair<int, int> arr[200001] = {};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)	
		cin >> arr[i].first >> arr[i].second;

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		pq.push(arr[i].second);
		if (pq.top() <= arr[i].first)
			pq.pop();
	}
	cout << pq.size();

	return 0;
}
