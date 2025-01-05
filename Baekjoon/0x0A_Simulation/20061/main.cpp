#include <iostream>
#include <cstring>

using namespace std;

int green[13][4] = {};
int blue[13][4] = {};
int n;

void	setRed(int t, int r, int c);
int		downBlock(int arr[13][4]);
bool	isOverlap(int arr[13][4], int gap);
int		isOverflow(int arr[13][4]);
int		isFull(int arr[10][4]);

// 출력용
void printBoard();

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int t, r, c;
	int score = 0;
	while (n--)
	{
		cin >> t >> r >> c;
		setRed(t, r, c);
		score += downBlock(green);	
		score += downBlock(blue);
	}
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j] == 1)
				cnt++;
			if (blue[i][j] == 1)
				cnt++;
		}
	}
	cout << score << " " << cnt << "\n";

	return 0;
}

int downBlock(int arr[13][4])
{
	int score = 0;
	int i;
	for (i = 2; i < 9 && !isOverlap(arr, i+1); i++) ;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (arr[x][y] == 1)
				arr[x+i][y] = 1;
		}
	}
	while (1)
	{
		int idx = isFull(arr);
		if (idx == 0)
			break;
		score++;
		for (int i = 0; i < 4; i++)
			arr[idx][i] = 0;
		for (int i = idx; i > 4; i--)
			for (int j = 0; j < 4; j++)
				arr[i][j] = arr[i-1][j];
	}
	int over = isOverflow(arr);
	if (over)
	{
		for (int i = 0; i < over; i++)
		{
			for (int j = 0; j < 4; j++)
				arr[9 - i][j] = 0;
		}
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				arr[9 - i][j] = arr[9 - i - over][j];
	}
	bzero(arr, 24 * sizeof(int));
	return score;
}

int isOverflow(int arr[13][4])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[4 + i][j] == 1)
				return 2 - i;
		}
	}
	return 0;
}

int isFull(int arr[10][4])
{
	for (int i = 9; i >= 6; i--)
	{
		if (arr[i][0] && arr[i][1] && arr[i][2] && arr[i][3])
			return i;
	}
	return 0;
}

bool isOverlap(int arr[13][4], int gap)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 1 && (arr[i+gap][j] == 1 || i + gap >= 10))
				return true;
		}
	}
	return false;
}

void setRed(int t, int r, int c)
{
	if (t == 1)
	{
		green[r][c] = 1;
		blue[c][3 - r] = 1;
	}
	else if (t == 2)
	{
		green[r][c] = 1;
		green[r][c + 1] = 1;
		blue[c][3 - r] = 1;
		blue[c + 1][3 - r] = 1;
	}
	else if (t == 3)
	{
		green[r][c] = 1;
		green[r + 1][c] = 1;
		blue[c][3 - r] = 1;
		blue[c][2 - r] = 1;
	}
}

void printBoard()
{
		cout << "GREEN\n";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << green[i][j];
			cout << "\n";
		}
		cout << "\nBLUE\n";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 4; j++)
				cout << blue[i][j];
			cout << "\n";
		}
}