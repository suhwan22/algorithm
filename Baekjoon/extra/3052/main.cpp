#include <iostream>
#include <map>

int main()
{
  std::map<int, int> a;
  int input;
  int cnt = 0;

  for (int i = 0; i < 10; i++)
  {
    std::cin >> input;
    if (a[input % 42])
      continue;
    else
    {
      a[input % 42] = input;
      cnt++;
    }
  }
  std::cout << a.size();
}