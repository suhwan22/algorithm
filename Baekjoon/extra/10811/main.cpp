/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-17 00:24:13
 * Updated     : 2025-04-17 00:27:56
 */

#include <iostream>

using namespace std;

int n, m;
int arr[101];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        arr[i] = i;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = a; j < (a + b + 1) / 2; j++)
            swap(arr[j], arr[b - (j - a)]);
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
    return 0;
}