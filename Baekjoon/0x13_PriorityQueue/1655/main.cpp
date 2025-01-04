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
	cin >> input;
	lq.push(input);
	cout << lq.top() << "\n";
	for (int i = 2; i <= n; i++)
	{
		cin >> input;
		if (i % 2 == 0)
		{
			if (lq.top() <= input)
				rq.push(input);
			else
			{
				rq.push(lq.top());
				lq.pop();
				lq.push(input);
			}	
		}
		else
		{
			if (rq.top() > input)
				lq.push(input);
			else
			{
				lq.push(rq.top());
				rq.pop();
				rq.push(input);
			}
		}
		cout << min(lq.top(), rq.top()) << "\n";
	}

	return 0;
}