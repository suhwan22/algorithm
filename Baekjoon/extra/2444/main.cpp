/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-12 20:39:44
 * Updated     : 2025-04-13 04:38:28
 */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
            cout << " ";
        for (int j = 0; j < 1 + (i - 1) * 2; j++)
            cout << "*";
        cout << "\n";
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n - i; j++)
            cout << " ";
        for (int j = 0; j < 1 + (i - 1) * 2; j++)
            cout << "*";
        cout << "\n";
    }
}
