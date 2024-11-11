#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student
{
  string name;
  int korea;
  int english;
  int math;
};

bool comp(const Student &a, const Student &b)
{
  if (a.korea != b.korea)
    return a.korea > b.korea;
  if (a.english != b.english)
    return a.english < b.english;
  if (a.math != b.math)
    return a.math > b.math;
  return a.name < b.name;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  string name;
  Student student;
  vector<Student> arr;
  for (int i = 0; i < n; i++)
  {
    cin >> student.name >> student.korea >> student.english >> student.math;
    arr.push_back(student);
  }

  sort(arr.begin(), arr.end(), comp);

  for (auto student : arr)
    cout << student.name << "\n";

  return 0;
}