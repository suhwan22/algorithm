/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj-1918
 * Created     : 2025-02-21 18:48:22
 * Updated     : 2025-02-21 21:20:32
 */

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack<char> op;
string input;

bool comp(char a, char b);
void opPop();

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> input;
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (isalpha(input[i]))
			cout << input[i];
		else
		{
			if (op.empty() || input[i] == '(')
				op.push(input[i]);
			else if (input[i] == ')')
			{
				while (op.top() != '(')
					opPop();
				op.pop();
			}
			else
			{
				while (!op.empty() && comp(op.top(), input[i]))
					opPop();
				op.push(input[i]);
			}
		}
	}
	while (!op.empty())
		opPop();

	return 0;
}

void opPop()
{
	cout << op.top();
	op.pop();
}

bool comp(char a, char b)
{
	if (a == '(')
		return false;
	if (b == '*' || b == '/')
	{
		if (a == '*' || a == '/')
			return true;
		return false;
	}
	return true;
}