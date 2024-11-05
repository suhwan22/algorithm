#include <iostream>

using namespace std;

class Stack
{
private:
	int* arr;
	int max;
	int idx = 0;
public:
	Stack(int m) : max(m)
	{
		arr = new int[m];
	}
	void push(int e)
	{
		if (idx > max - 1)
		{
			cout << "더이상 저장 할 수 없습니다.\n";
			return;
		}
		arr[idx] = e;
		idx++;
	}
	int pop()
	{
		idx--;
		int value = arr[idx];
		return value;
	}
	bool full()
	{
		if (idx > max - 1)
			return true;
		else
			return false;
	}
	void ShowStack()
	{
		for (int i = 0; i < max; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	~Stack()
	{
		delete[] arr;
	}
};

void dosomething(int* arr, int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	dosomething(arr, n, m);
	return 0;
}

void dosomething(int* arr, int n, int m)
{
	static Stack st(m);
	for (int i = 0; i < n; i++)
	{
		st.push(arr[i]);
		if (st.full())
		{
			st.ShowStack();
			st.pop();
		}
		else
		{
			dosomething(arr, n, m);
			st.pop();
		}
	}
}