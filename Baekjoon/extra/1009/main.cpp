/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-12 20:23:55
 * Updated     : 2025-04-12 20:29:47
 */

#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        long long a, b, r = 1;
        cin >> a >> b;
        for (int i = 0; i < b; i++)
            r = (r * a) % 10;
        cout << (r == 0 ? 10 : r) << "\n";
    }
}