#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
int n, m;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	long long input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		pq.push(input);
	}
	while (m--)
	{
		long long a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		a = a + b;
		b = a;
		pq.push(a);
		pq.push(b);
	}
	
	long long sum = 0;
	while (!pq.empty())
	{
		sum += pq.top();
		pq.pop();
	}
	cout << sum;

	return 0;
}
