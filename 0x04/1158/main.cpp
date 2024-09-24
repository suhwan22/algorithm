#include <iostream>
#include <list>

using namespace std;

list<int>::iterator myNext(list<int>& arr, list<int>::iterator it, int k)
{
  while (k--)
  {
    if (it == arr.end())
      it = next(arr.begin(), 1);
    else
      it++;
  }

  return it;
}

/**
 * List<int> arr 출력용 함수
 */
void printList(list<int> arr)
{
  cout << "current arr = [";
  for (list<int>::iterator it = arr.begin(); it != arr.end(); it++)
  {
    cout << *it;
    if (arr.size() != 0 && it != prev(arr.end(), 1))
      cout << ", ";
  }
  cout << "]\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;

  cin >> n >> k;

  list<int> arr;

  for (int i = 1; i <= n; i++)
    arr.push_back(i);

  // printList(arr);
  list<int>::iterator it = arr.begin();
  list<int>::iterator target;

  cout << "<";
  while (arr.size() > 0)
  {
    it = myNext(arr, it, k);
    target = prev(it, 1);
    cout << *target;
    if (arr.size() != 1)
      cout << ", ";
    it = arr.erase(target, it);
    // printList(arr);
  }
  cout << ">";

  return 0;
}