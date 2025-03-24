/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-2143
 * Created     : 2025-03-24 17:05:33
 * Updated     : 2025-03-24 17:45:00
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, m;
int Aarr[1000];
int Barr[1000];
vector<long long> A, B;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> Aarr[i];
	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += Aarr[j];
			A.push_back(sum);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> Barr[i];
	for (int i = 0; i < m; i++)
	{
		long long sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += Barr[j];
			B.push_back(sum);
		}
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	long long cnt = 0;
	for (int i = 0; i < (int)A.size(); i++)
	{
		long long sum = t - A[i];
		auto up = upper_bound(B.begin(), B.end(), sum);
		auto low = lower_bound(B.begin(), B.end(), sum);
		cnt += up - low;
	}
	cout << cnt;

	return 0;
}
