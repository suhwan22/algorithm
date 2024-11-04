#include <iostream>
#include <cmath>

using namespace std;

pair<double, double> arr[10000] = {};

double shoelace(double x1, double y1, double x2, double y2, double x3, double y3);

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  double n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i].first >> arr[i].second;
  
  double ans = 0;
  
  for (int i = 2; i < n; i++)
  {
    ans += shoelace(arr[0].first, arr[0].second, arr[i-1].first, arr[i-1].second, arr[i].first, arr[i].second);
  }
  cout << fixed;
  cout.precision(1);
  cout << abs(ans);

  return 0;
}

double shoelace(double x1, double y1, double x2, double y2, double x3, double y3)
{
  return (1/2.0 * ((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)));
}