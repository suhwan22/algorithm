/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-15 22:19:57
 * Updated     : 2025-04-15 22:21:45
 */

#include <iostream>

using namespace std;

int arr[1000000];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int b, c;
    cin >> b >> c;
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] -= b;
        cnt++;
        if (arr[i] > 0)
            cnt += arr[i] / c + (arr[i] % c == 0 ? 0 : 1);
    }
    cout << cnt;
    return 0;
}