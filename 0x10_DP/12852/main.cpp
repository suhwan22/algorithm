#include <iostream>
#include <map>

using namespace std;

//D[i].first = i 가 1위 되는데 걸리는 횟수 라하자
//D[12].first = min(D[4].first + 1, D[6].first + 1, D[11].first + 1)
//D[k].first = min(D[k/3].first + 1, D[k/2].first + 1, D[k-1].first + 1)
// 이런 느낌으로 점화식 세우고 저장하는 듯
// 이제 출력을 하기 위해서 지금 찾은 최솟값이 어디서 온건지 idx 저장하자
// D[n].second = pre idx

pair<int, int> D[1000001] = {};

int main()
{
  int n;
  cin >> n;

  D[1].first = 0;
  D[1].second = 1;
  for (int i = 2; i <= n; i++)
  {
    D[i].first = D[i - 1].first + 1;
    D[i].second = i - 1;
    if (i % 2 == 0)
    {
      if (D[i].first > D[i/2].first+1)
      {
        D[i].first = D[i/2].first+1;
        D[i].second = i/2;
      }
    }
    if (i % 3 == 0)
    {
      if (D[i].first > D[i/3].first + 1)
      {
        D[i].first = D[i/3].first + 1;
        D[i].second = i/3;
      }
    }
  }

  cout << D[n].first << "\n";
  int cur = n;
  while (cur != 1)
  {
    cout << cur << " ";
    cur = D[cur].second;
  }
  cout << 1;
}