#include <iostream>
#include <vector>

int main()
{
  int n;
  std::vector<int>  vec(0);
  int input;
  
  std::cin >> n;
  while (n--)
  {
    std::cin >> input;
    vec.push_back(input);
  }
  int v;
  int cnt = 0;
  std::cin >> v;

  for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
  {
    if (*it == v)
      cnt++;
  }
  std::cout << cnt;
}