/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-05-11 00:40:35
 * Updated     : 2025-05-11 00:41:12
 */

#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j < i || j + i >= 2 * n)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            if (j < i || j + i >= 2 * n)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
}