#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<pair<long long, long long>> s)
{
  cout << "----stack----\n";
  for (;!s.empty();s.pop())
  {
    cout << "" << s.top().first << ": " << s.top().second << "\n";
  }
  cout << "-------------\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long h;
  long long cnt;
  long long temp;
  long long max = 0;

  while (1)
  {
    stack<pair<long long, long long>> s;
    cin >> n;
    max = 0;
    if (n == 0)
      break;
    //run
    while (n--)
    {
      cin >> h;
      cnt = 0;
      while (!s.empty() && s.top().first > h)
      {
        // pop 하면서 정리
        if (max < s.top().first * (s.top().second + cnt))
          max = s.top().first * (s.top().second + cnt);
        cnt += s.top().second;
        s.pop();
      }
      if (!s.empty() && s.top().first == h)
      {
        // pop 다했는데 같은게 남은 경우
        cnt += s.top().second;
        s.pop();
        s.push({h, cnt + 1});
      }
      else
      {
        // pop 다 했는데 그냥 다른경우(일반적인 경우)
        // 쌓인 cnt 더해주고 나는 새로 하나 쌓고
        s.push({h, cnt + 1});
      }
      // printStack(s);
    }
    cnt = 0;
    while (!s.empty())
    {
      if (s.top().first * (s.top().second + cnt) > max)
        max = s.top().first * (s.top().second + cnt);
      cnt += s.top().second;
      s.pop();
    }
  
    cout << max << "\n";
  }

  return 0;
}