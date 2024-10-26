#include <iostream>
#include <queue>

using namespace std;

void printBridge(queue<int> b);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, w, l;
  cin >> n >> l >> w;
  // 와 왜 문제에서는 w 가 길이고 l 이 최대하중이냐?.. 극혐,,
  // 난 n가 트럭 개수, w가 최대하중, l이 다리 길이
  queue<int> truck;
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    truck.push(input);
  }

  // 이미 올라간 애들 먼저 보내고 다리 하중 계산하고 올릴 수 있으면 올리고
  int curW = 0;
  int time = 0;
  int outW;
  queue<int> bridge;
  for (int i = 0; i < l; i++)
    bridge.push(0);

  while (1)
  {
    outW = bridge.front();
    bridge.pop();
    curW -= outW;
    if (!truck.empty() && truck.front() + curW <= w)
    {
      bridge.push(truck.front());
      curW += truck.front();
      truck.pop();
    }
    else
      bridge.push(0);
    time++;
    if (curW == 0 && truck.empty())
      break;
  }

  cout << time;

  return 0;
}

void printBridge(queue<int> b)
{
  while (!b.empty())
  {
    cout << b.front() << " ";
    b.pop();
  }
  cout << "\n";
}