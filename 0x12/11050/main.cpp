#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> a >> b;
    long long c = 1;
    for (int i = 0; i < b; i++)
        c *= (a - i);
    for (int i = b; i > 1; i--)
        c /= i;
    cout << c;
    
    return 0;
}