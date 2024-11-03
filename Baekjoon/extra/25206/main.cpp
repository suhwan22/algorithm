#include <iostream>
#include <sstream>
#include <iomanip>

int main()
{
	double	totalCourse = 0;
	double	course;
	double	totalGrade = 0;
	std::string	name;
	std::string	grade;
	std::string	input;
	
	for (int i = 0; i < 20; i++)
	{
		std::cin >> name >> course >> grade;
		totalCourse += course;
		if (grade == "A+")
		{
			totalGrade += 4.5 * course;
		}
		else if (grade == "A0")
		{
			totalGrade += 4.0 * course;
		}
		else if (grade == "B+")
		{
			totalGrade += 3.5 * course;
		}
		else if (grade == "B0")
		{
			totalGrade += 3.0 * course;
		}
		else if (grade == "C+")
		{
			totalGrade += 2.5 * course;
		}
		else if (grade == "C0")
		{
			totalGrade += 2.0 * course;
		}
		else if (grade == "D+")
		{
			totalGrade += 1.5 * course;
		}
		else if (grade == "D0")
		{
			totalGrade += 1.0 * course;
		}
		else if (grade == "F")
		{
			totalGrade += 0 * course;
		}
		else if (grade == "P")
		{
			totalCourse -= course;
		}
	}
	std::cout << std::fixed << std::setprecision(6) << totalGrade / totalCourse;
}
