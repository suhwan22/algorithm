#include <iostream>

int main()
{
  int n = 1;
  int max;
  int idx = 1;
  int input;

  std::cin >> max;

  while (n++ < 9)
  {
    std::cin >> input;
    if (max < input)
    {
      idx = n;
      max = input;
    }
  }
  std::cout << max << "\n" << idx;

}