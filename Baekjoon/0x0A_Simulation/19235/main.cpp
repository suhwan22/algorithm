#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int green[13][4] = {};
int blue[13][4] = {};
int n;

void	setRed(int t, int r, int c, int i);
int		downBlock(int arr[13][4]);
bool	isOverlap(int arr[13][4], int gap);
int		isOverflow(int arr[13][4]);
int		isFull(int arr[10][4]);
vector<pair<int, int>> isEnableBlock(int arr[10][4]);

void printBoard();

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int t, r, c;
	int score = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> t >> r >> c;
		setRed(t, r, c, i);
		score += downBlock(green);
		score += downBlock(blue);
	}
	int cnt = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j] != 0)
				cnt++;
			if (blue[i][j] != 0)
				cnt++;
		}
	}
	cout << score << "\n" << cnt;

	return 0;
}

int downBlock(int arr[13][4])
{
	int score = 0;
	int i;
	// red에 있는 블록을 몇칸 내릴지 결정
	for (i = 2; i < 9 && !isOverlap(arr, i+1); i++) ;

	// 실제로 red에 있는 블록을 i칸 내린다.
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (arr[x][y] != 0)
				arr[x+i][y] = arr[x][y];
		}
	}

	while (1)
	{
		int idx;
		// 가득찬 줄이 있으면 지우고 한줄 내려주기
		while (1)
		{
			idx = isFull(arr);
			if (idx == 0)
				break;
			score++;
			for (int i = 0; i < 4; i++)
				arr[idx][i] = 0;
			for (int i = idx; i > 4; i--)
				for (int j = 0; j < 4; j++)
					arr[i][j] = arr[i - 1][j];
		}
		// 더 내려갈 블록 확인해서 내리기
		vector<pair<int, int>> block;
		bool find = false;	
		while (1)
		{
			block = isEnableBlock(arr);
			if (block.empty())
				break;
			find = true;
			int temp = arr[block[0].first][block[0].second];
			for (auto p : block)
			{
				arr[p.first][p.second] = 0;
				arr[p.first + 1][p.second] = temp;
			}
		}
		// 가득찬 줄도 없었고 더 이상 내려갈 블록도 없으면 탈출
		if (idx == 0 && !find)
			break;
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
		{
			for (int j = 0; j < 4; j++)
				arr[9 - i][j] = arr[9 - i - over][j];
		}
	}
	bzero(arr, 24 * sizeof(int));
	return score;
}

vector<pair<int, int>> isEnableBlock(int arr[10][4])
{
	for (int i = 8; i >= 6; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] != 0)
			{
				int dx[5] = {0, 1, -1, 0, 0};
				int dy[5] = {0, 0, 0, 1, -1};
				vector<pair<int, int>> block;
				for (int k = 0; k < 5; k++)
				{
					if (arr[i + dx[k]][j + dy[k]] == arr[i][j])
						block.push_back({i + dx[k], j + dy[k]});
				}
				bool en = true;
				for (auto p : block)
				{
					if (p.first + 1 > 9 || (arr[p.first + 1][p.second] != arr[i][j] && arr[p.first + 1][p.second] != 0))
						en = false;
				}
				if (en)
					return block;
			}
		}
	}
	return vector<pair<int, int>>();
}

int isOverflow(int arr[13][4])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[4 + i][j] != 0)
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
			if (arr[i][j] != 0 && (arr[i+gap][j] != 0 || i + gap >= 10))
				return true;
		}
	}
	return false;
}

void setRed(int t, int r, int c, int i)
{
	if (t == 1)
	{
		green[r][c] = i;
		blue[c][3 - r] = i;
	}
	else if (t == 2)
	{
		green[r][c] = i;
		green[r][c + 1] = i;
		blue[c][3 - r] = i;
		blue[c + 1][3 - r] = i;
	}
	else if (t == 3)
	{
		green[r][c] = i;
		green[r + 1][c] = i;
		blue[c][3 - r] = i;
		blue[c][2 - r] = i;
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