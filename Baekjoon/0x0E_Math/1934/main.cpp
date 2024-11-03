#include <iostream>
#include <queue>

using namespace std;

int gcd(int a, int b);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int a, b;
    while (n--)
    {
        cin >> a >> b;
        cout << a / gcd(a, b) * b << "\n";
    }
    
    return 0;
}

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}