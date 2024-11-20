#include <iostream>

using namespace std;

// 최댓값을 찾고 그거보다 작은 인덱스들을 해당 최댓값에 팔면 되는데
// 이러면 매번 최댓값을 찾는데 O(N)이 걸려서
// 최악의 경우 O(N*N)이 될 수도 있다.
// 그래서 인덱스를 거꾸로 접근하면서 최댓값을 저장하고 진행하면서 최댓값 보다 작으면
// 바로 그 차이 만큼이 이익, 새로운 최댓값을 발견하면 max 변경해주고 계속 진행

int board[1000000] = {};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> board[i];
    int max = -1;
    long long cost = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      if (max < board[i])
        max = board[i];
      else
        cost += max - board[i];
    }
    cout << cost << "\n";
  }

  return 0;
}