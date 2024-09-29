#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie();

	int n;
	cin >> n;

	deque<int> d;
	int input;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		d.push_back(input);
	}

	sort(d.begin(), d.end());
	// for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	// 	cout << *it << " ";
	// cout << "\n";

	long long sum = 0;
	int ddd = -4001;
	int dd = 0;
	int cnt = 1;
	bool flag;
	int cnt_max = 0;
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
	{
		sum += *it;
		if (it + 1 != d.end() && *it == *(it + 1))
			cnt++;
		else
		{
			if (cnt_max < cnt)
			{
				cnt_max = cnt;
				dd = *it;
				ddd = -4001;
			}
			else if (cnt_max == cnt)
			{
				// cout << "?\n";
				if (ddd == -4001)
					ddd = *it;
			}
			cnt = 1;
		}
	}
	// cout << "sum : " << sum << "\n";
	double av = (double)sum / n;
	cout << (long long)round(av) << "\n";
	cout << d.at(n/2) << "\n";
	if (ddd != -4001)
		cout << ddd << "\n";
	else
		cout << dd << "\n";
	cout << *(d.end() - 1) - *(d.begin()) << "\n";

	return 0;
}
