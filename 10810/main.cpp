 #include <iostream> 
  
int main()
{
  std::ios::sync_with_stdio(false);
	std::cin.tie(0);

  int n, m;

  std::cin >> n >> m;

  int *arr = new int[n + 1];
  for (int i = 0; i <= n; i++)
    arr[i] = 0;

  int a, b, c;

  while (m--)
  {
    std::cin >> a >> b >> c;
    for (int j = a; j <= b; j++){
      arr[j] = c;
    }
  }

  for (int j = 1; j < n + 1; j++)
  {
    std::cout << arr[j];
    if (j != n)
      std::cout << " ";
  }
}