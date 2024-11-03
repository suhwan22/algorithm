#include <iostream>

int main()
{
	int hour, min;
	int time;

	std::cin >> hour >> min;
	std::cin >> time;

	while (time > 60)
	{
		hour++;
		time -= 60;
	}
	min += time;

	while (hour >= 24)
		hour -= 24;
	if (min >= 60)
	{
		min -= 60;
		hour++;
		if (hour >= 24)
			hour = 0;
	}

	std::cout << hour << " " << min;
}
