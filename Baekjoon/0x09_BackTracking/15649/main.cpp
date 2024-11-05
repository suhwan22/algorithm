#include <iostream>

using namespace std;

class Stack
{
private :
	int* arr;
	int max;
	int idx = 0;
public :
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

void nPm(int* check, int* arr, int n, int m);

int main()
{
	int n, m;
	cin >> n >> m;
	int* arr = new int[n];
	int* check = new int[n];
	for (int i = 0; i < n; i++)
	{
		check[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		arr[i - 1] = i;
	}
	nPm(check ,arr, n, m);
	delete[] arr;
	delete[] check;
	return 0;
}

void nPm(int* check ,int* arr, int n, int m)
{
	static Stack st(m);
	for (int i = 0; i < n; i++)
	{
		if (check[i] == 0)
		{
			st.push(arr[i]);
			check[i] = 1;
		}
		else
		{
			continue;
		}
		if (st.full())
		{
			st.ShowStack();
			check[st.pop() - 1] = 0;
		}
		else
		{
			nPm(check, arr, n, m);
			check[st.pop() - 1] = 0;
		}
	}
}