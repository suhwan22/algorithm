#include <iostream>

int main()
{
  std::ios::sync_with_stdio(false);
	std::cin.tie(0);

  int num1, num2;

  while (1)
  {
    std::cin >> num1 >> num2;
    if (num1 == 0 && num2 == 0)
      break;
    std::cout << num1 + num2 << "\n";
  }
}