#include <iostream>
#include <set>
#include <map>

using namespace std;

int n, k;
int seq[100] = {};
set<int> plug;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> k;
	int cnt = 0;
	for (int i = 0; i < k; i++)
		cin >> seq[i];
	for (int i = 0; i < k; i++)
	{
		if (plug.find(seq[i]) != plug.end()) // 이미 사용중인 용품
			continue;
		else if ((int)plug.size() < n) // n개 보다 적은 용품을 사용중인 경우
			plug.insert(seq[i]);
		else // 모든 콘센트를 사용중인 경우
		{
			set<int> temp(plug);
			for (int j = i + 1; j < k; j++)
			{
				if ((int)temp.size() == 1)
					break;
				if (temp.find(seq[j]) != temp.end())
					temp.erase(seq[j]);
			}
			plug.erase(*(temp.begin()));
			cnt++;
			plug.insert(seq[i]);
		}
	}
	cout << cnt;

	return 0;
}
