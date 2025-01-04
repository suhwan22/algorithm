#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> rq;
priority_queue<int> lq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int input;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		if (lq.empty() || input < lq.top())
			lq.push(input);
		else
			rq.push(input);
		if (lq.size() > rq.size() + 1)
		{
			rq.push(lq.top());
			lq.pop();
		}
		else if (rq.size() > lq.size())
		{
			lq.push(rq.top());
			rq.pop();
		}
		cout << lq.top() << "\n";
	}

	return 0;
}