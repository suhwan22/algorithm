/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-9935
 * Created     : 2025-03-23 19:22:41
 * Updated     : 2025-03-24 23:19:26
 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	string input, target, output;
	cin >> input >> target;
	int len = target.length();
	for (int i = 0; i < (int)input.size(); i++)
	{
		output.push_back(input[i]);
		while ((int)output.size() >= len && strcmp(output.c_str() + output.size() - len, target.c_str()) == 0)
			output.erase(output.end() - len, output.end());
	}
	if (output.empty())
		cout << "FRULA";
	else
		cout << output;

	return 0;
}
