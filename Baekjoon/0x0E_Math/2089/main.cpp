#include <iostream>

using namespace std;

int n;
void negativeBase(int a);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	negativeBase(n);

	return 0;
}

void negativeBase(int a)
{
	if (a == 0 || a == 1)
		cout << a;
	else
	{
		int b = a > 0 ? a : a - 1;
		negativeBase(b / -2);
		cout << a - b / -2 * -2;
	}
}