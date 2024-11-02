#include <iostream>
#include <stack>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  // stack 에 push 하면서 지금 top 이 나보다 크면 현재 stack size 만큼 cnt에 더해주고
  // 만약 top 보다 내가 크면 나보다 큰값 나올때 까지 pop 하고 나보다 큰값 나오면 stack size 만큼 cnt에 더하고
  // push 반복

  int n;
  cin >> n;
  int h;
  long long cnt = 0;
  stack<int> s;

  for (int i = 0; i < n; i++)
  {
    cin >> h;
    while (!s.empty() && s.top() <= h)
    {
      s.pop();
    }
    cnt += s.size();
    s.push(h);
  }
  cout << cnt;
  
  return 0;
}