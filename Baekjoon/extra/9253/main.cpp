#include <iostream>
#include <cstring>

using namespace std;

string a, b, c;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> a >> b >> c;
	if (strstr(a.c_str(), c.c_str()) != NULL && strstr(b.c_str(),c.c_str()) != NULL)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
