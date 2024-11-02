#include <iostream>

using namespace std;

int q[2000001];
int f = 2000000;
int b = 2000000;

int size()
{
  return f - b;
}

bool empty()
{
  if (size() == 0)
    return true;
  return false;
}

void push(int a)
{
  q[b--] = a;
}

int pop()
{
  if (!empty())
    return q[f--];
  return -1;
}

int front()
{
  if (!empty())
    return q[f];
  return -1;
}

int back()
{
  if (!empty())
    return q[b + 1];
  return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	int b;
	cin >> n;
	string s;

	while (n--)
	{
		cin >> s;
		if (s == "push")
		{
			cin >> b;
			push(b);
		}
		else if (s == "pop")
			cout << pop() << "\n";
		else if (s == "front")
			cout << front() << "\n";
		else if (s == "back")
			cout << back() << "\n";
		else if (s == "empty")
			cout << empty() << "\n";
		else if (s == "size")
			cout << size() << "\n";
    else
      cout << "ha?\n";
	}
	return 0;
}