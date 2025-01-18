#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> shark = {-1, -1};
int sharkDir = 0;

pair<int, int> input[4][4];
pair<int, int> fishes[17];

int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int nx, ny;
int max = 0, score = 0;

void play(pair<int, int> fish[17], pair<int, int> board[4][4]);

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> input[i][j].first >> input[i][j].second;
			fishes[input[i][j].first] = {i, j};
		}
	}
	play(fishes, input);
	cout << ::max;

	return 0;
}

void play(pair<int, int> fish[17], pair<int, int> board[4][4])
{
	pair<int, int> nextFish[17];
	pair<int, int> nextBoard[4][4];

	vector<pair<int, int>> nxt;
	pair<int, int> cur = shark;

	if (shark.first == -1)
		nxt.push_back({0, 0});
	else
	{
		for (int i = 1; i <= 3; i++)
		{
			nx = cur.first + dx[sharkDir] * i;
			ny = cur.second + dy[sharkDir] * i;
			if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || board[nx][ny].first == 0)
				continue;
			nxt.push_back({nx, ny});
		}
	}
	
	pair<int, int> curShark = shark;
	int curDir = sharkDir;

	for (auto n : nxt)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				nextBoard[i][j] = board[i][j];
		}
		for (int i = 0; i <= 16; i++)
			nextFish[i] = fish[i];
		
		// 상어 움직이기
		nextBoard[shark.first][shark.second] = {0, 0};
		nextFish[board[n.first][n.second].first] = {-1, -1};
		nextBoard[n.first][n.second].first = -1;
		score += board[n.first][n.second].first;
		shark = n;
		sharkDir = nextBoard[n.first][n.second].second;

		// 물고기 움직이기
		for (int i = 1; i <= 16; i++)
		{
			if (nextFish[i].first == -1) continue;
			cur = nextFish[i];
			int dir = nextBoard[cur.first][cur.second].second;
			int &ndir = nextBoard[cur.first][cur.second].second;
			while (1)
			{
				nx = cur.first + dx[ndir];
				ny = cur.second + dy[ndir];
				if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4 || nextBoard[nx][ny].first == -1)
				{
					ndir = ndir != 8 ? ndir + 1 : 1;
					// 8방향 모두 갈 수 없는 경우.
					// 아니 근데 이런경우가 어떻게 있지??
					// 실제로 해당 탈출 코드를 없애도 문제없이 통과가 된다.
					if (ndir == dir)
						break;
				}
				else
				{
					pair<int, int> temp = nextFish[i];
					nextFish[i] = {nx, ny};
					nextFish[nextBoard[nx][ny].first] = temp;

					temp = nextBoard[nx][ny];
					nextBoard[nx][ny] = nextBoard[cur.first][cur.second];
					nextBoard[cur.first][cur.second] = temp;
					break;
				}
			}
		}
		play(nextFish, nextBoard);
		score -= board[n.first][n.second].first;
		shark = curShark;
		sharkDir = curDir;
	}
	if (::max < score)
		::max = score;
}