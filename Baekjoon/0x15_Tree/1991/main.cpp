#include <iostream>

using namespace std;

int tree[2][27] = {};
int n;

void preorder(int p);
void inorder(int p);
void postorder(int p);

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  char a, b, c;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b >> c;
    if (b != '.')
      tree[0][a - 'A' + 1] = b - 'A' + 1;
    if (c != '.')
      tree[1][a - 'A' + 1] = c - 'A' + 1;
  }
  preorder(1);
  cout << "\n";
  inorder(1);
  cout << "\n";
  postorder(1);

  return 0;
}

void preorder(int p)
{
  cout << (char)(p + 'A' - 1);
  if (tree[0][p] != 0)
    preorder(tree[0][p]);
  if (tree[1][p] != 0)
    preorder(tree[1][p]);
}

void inorder(int p)
{
  if (tree[0][p] != 0)
    inorder(tree[0][p]);
  cout << (char)(p + 'A' - 1);
  if (tree[1][p] != 0)
    inorder(tree[1][p]);
}

void postorder(int p)
{
  if (tree[0][p] != 0)
    postorder(tree[0][p]);
  if (tree[1][p] != 0)
    postorder(tree[1][p]);
  cout << (char)(p + 'A' - 1);
}