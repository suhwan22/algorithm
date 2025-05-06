/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-05-06 21:53:13
 * Updated     : 2025-05-06 22:10:28
 */

#include <iostream>
#include <map>

using namespace std;

map<string, string> p;
map<string, int> cnt;
int tc;

string find(string &str);
int uni(string a, string b);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		string u, v;
		p.clear();
		cnt.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> u >> v;
			cout << uni(u, v) << "\n";
		}
	}

	return 0;
}

string find(string &str)
{
	if (p[str] == "")
		return str;
	return p[str] = find(p[str]);	
}

int uni(string a, string b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return cnt[a];
	if (cnt[a] == 0)
		cnt[a] = 1;
	if (cnt[b] == 0)
		cnt[b] = 1;
	if (cnt[a] < cnt[b])
		swap(a, b);
	cnt[a] += cnt[b];
	p[b] = a;
	return cnt[a];
}