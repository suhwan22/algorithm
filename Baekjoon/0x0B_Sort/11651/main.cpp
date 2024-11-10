#include <iostream>

using namespace std;

class Point
{
private :
	int xpos, ypos;
public :
	Point(int x=0, int y=0) : xpos(x), ypos(y) { }
	void exchangepos(Point& pos)
	{
		int temp;
		temp = xpos;
		xpos = pos.xpos;
		pos.xpos = temp;
		temp = ypos;
		ypos = pos.ypos;
		pos.ypos = temp;
	}
	bool operator>(const Point& pos) const
	{
		if (ypos < pos.ypos)
			return false;
		else if (ypos == pos.ypos)
		{
			if (xpos < pos.xpos)
				return false;
			else
				return true;
		}
		else
			return true;
	}
	bool operator<(const Point& pos) const
	{
		if (ypos > pos.ypos)
			return false;
		else if (ypos == pos.ypos)
		{
			if (xpos > pos.xpos)
				return false;
			else
				return true;
		}
		else
			return true;
	}

	int Getxpos()
	{
		return xpos;
	}
	int Getypos()
	{
		return ypos;
	}
	void ShowInfo()
	{
		cout << xpos << " " << ypos << "\n";
	}
};

void binarytree(Point* arr, int size);
void heapsort(Point* arr, int size);

int main()
{
	int n;
	cin >> n;
	Point* arr = new Point[n];
	int x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		arr[i] = Point(x,y);
	}
	binarytree(arr, n);
	heapsort(arr, n);
	for (int j = 0; j < n; j++)
		arr[j].ShowInfo();
	return 0;
}

void binarytree(Point* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (arr[root] < arr[c])
				arr[root].exchangepos(arr[c]);
			c = root;
		} while (c != 0);
	}
}

void heapsort(Point* arr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		int root = 0;
		arr[root].exchangepos(arr[i]);
		int a;
		do
		{
			a = 2 * root + 1;
			if (a < i - 1 && arr[a] < arr[a + 1])
				a++;
			if (a < i && arr[root] < arr[a])
				arr[root].exchangepos(arr[a]);
			root = a;
		} while (2 * a + 1 < i);
	}
}