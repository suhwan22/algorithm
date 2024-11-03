#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  // 1 <= n <= 1,000,000
  int input;
  for (int i = 0; i < n; i++)
  {
    cin >> input;
    // -10^9 <= input <= 10^9
    arr.push_back(input);
  }


  // arr'[i] = arr[i] 보다 작은 모든 arr[j] 의 종류의 개수 (단, i != j)
  // 정렬하고 나랑 같은 친구들 중 제일 왼쪽idx 하면 되는거 아닌가?..
  // 아 정렬하면 원래 arr 가 없어지는데 원래 arr[i] 순서로 출력해야 하는 구나
  // 원래 배열 냇두고 복사해서 써야겠다.
  // 매번 그때 그때 찾는게 편하긴 하겠다.

  // arr[i] 가 arr1 에서 lower_bound? 찾으면 될거같긴 한데?
  // 근데 중복을 제거 해야 되네

  vector<int> arr1 = arr;
  sort(arr1.begin(), arr1.end());
  arr1.erase(unique(arr1.begin(), arr1.end()), arr1.end());

  // unique 를 이용해서 중복을 제거하는 방식

  for (int i = 0; i < n; i++)
  {
    cout << lower_bound(arr1.begin(), arr1.end(), arr[i]) - arr1.begin() << " ";
  }

  return 0;
}