#include <iostream>

int main()
{
  std::ios::sync_with_stdio(false);
	std::cin.tie(0);

  int n;

  std::cin >> n;

  while(n >= 4)
  {
    std::cout << "long ";
    n -= 4;
  }
  std::cout << "int";
}