#include <iostream>

using namespace std;

int arr[1000000];
int temp[1000000];

void mergeSort(int begin, int end);
void merge(int begin, int end);

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  mergeSort(0, n);
  

  for (int i = n - 1; i >= 0; i--)
    cout << arr[i] << "\n";

  return 0;
}

// 0 1 2 3 4 5 6 7 8
// 0 9
// being ~ end - 1 까지 정렬
// (0, 4) (4, 9);
// (0, 2) (2, 4)      (4, 6) (6, 9)
// (0, 1) (1, 2) (2, 3) (3, 4) (4, 5) (5, 6) (6, 7) (7, 9)
//                                                  (7, 8) (8, 9)

void mergeSort(int begin, int end)
{
  int mid = (begin + end) / 2;
  if (end - begin == 1)
    return ;

  mergeSort(begin, mid);
  mergeSort(mid, end) ;
  merge(begin, end);
}

void merge(int begin, int end)
{
  int mid = (begin + end) / 2;
  int b = begin;
  int len = end - begin;

  for (int i = 0; i < len; i++)
  {
    if (mid >= end)
      temp[i] = arr[begin++];
    else if (begin >= (b + end) / 2)
      temp[i] = arr[mid++];
    else
    {
      if (arr[begin] <= arr[mid])
        temp[i] = arr[begin++];
      else
        temp[i] = arr[mid++];
    }
  }
  for (int i = 0; i < len; i++)
    arr[b + i] = temp[i];
}