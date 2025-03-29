/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://eventually-useful.tistory.com/16
 * Created     : 2025-03-27 22:16:31
 * Updated     : 2025-03-29 21:48:20
 */

#include <iostream>
#include <cstring>

using namespace std;

int t;
int visited[1024];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--)
	{
		int n, d;
		string output = "";
		bzero(visited, sizeof(visited));
		cin >> n >> d;
		output.append(to_string(n / d) + ".");
		n = (n % d) * 10;
		while (!visited[n / 10])
		{
			visited[n / 10] = output.size();
			output.push_back(n / d + '0');
			n = (n % d) * 10;
		}

		output.insert(output.begin() + visited[n / 10], '(');
		output.push_back(')');
		cout << output << "\n";
	}

	return 0;
}
