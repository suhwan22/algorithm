#include <iostream>

int main()
{
  std::ios::sync_with_stdio(false);
	std::cin.tie(0);

  int comp;
  int rot;
  int input = 0;
  int cost;
  int num;

  std::cin >> comp;
  std::cin >> rot;

  for (int i = 0; i < rot; i++)
  {
    std::cin >> cost >> num;
    input += cost * num;
  }

  if (input == comp)
    std::cout << "Yes";
  else
    std::cout << "No";
}
