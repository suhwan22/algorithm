#include <iostream>
#include <string>

using namespace std;

class OnlineJudge
{
private:
	string name;
	int age;
	int number;
	static int count;
public:
	OnlineJudge(string c="a", int a = 0) : name(c), age(a), number(count)
	{
		count++;
	}
	OnlineJudge& operator=(const OnlineJudge& ref)
	{
		name = ref.name;
		age = ref.age;
		return *this;
	}
	bool operator<(const OnlineJudge& ref)
	{
		if (age < ref.age)
			return true;
		else if(age > ref.age)
			return false;
		else
		{
			if (number < ref.number)
				return true;
			else
				return false;
		}
	}
	bool operator>(const OnlineJudge& ref)
	{
		if (age > ref.age)
			return true;
		else if (age < ref.age)
			return false;
		else
		{
			if (number > ref.number)
				return true;
			else
				return false;
		}
	}
	OnlineJudge& exchangejudge(OnlineJudge& ref)
	{
		string temps = name;
		name = ref.name;
		ref.name = temps;
		int temp = age;
		age = ref.age;
		ref.age = temp;
		temp = number;
		number = ref.number;
		ref.number = temp;
		return *this;
	}
	void ShowInfo()
	{
		cout << age << " " << name;
	}
	
};

int OnlineJudge::count = 0;

void binarytree(OnlineJudge* arr, int size);
void heapsort(OnlineJudge* arr, int size);

int main()
{
	int n;
	cin >> n;
	OnlineJudge* arr = new OnlineJudge[n];
	int age;
	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		arr[i] = OnlineJudge(name, age);
	}
	binarytree(arr, n);
	heapsort(arr, n);
	for (int j = 0; j < n; j++)
	{
		arr[j].ShowInfo();
		cout << "\n";
	}
	delete[] arr;
	return 0;
}

void binarytree(OnlineJudge* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (arr[root] < arr[c])
			{
				arr[root].exchangejudge(arr[c]);
			}
			c = root;
		} while (c != 0);
	}
}

void heapsort(OnlineJudge* arr, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		int root = 0;
		arr[root].exchangejudge(arr[i]);
		int a;
		do
		{
			a = 2 * root + 1;
			if (a < i - 1 && arr[a] < arr[a + 1])
			{
				a++;
			}
			if (a < i && arr[root] < arr[a])
			{
				arr[root].exchangejudge(arr[a]);
			}
			root = a;
		} while (2 * a + 1 < i);
	}
}