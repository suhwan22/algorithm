#include <iostream>

using namespace std;

int T[302] = {};
int W[301] = {};

int main()
{
    T[1] = 1;
    for (int i = 2; i < 302; i++)
    {
        T[i] = T[i-1] + i;
        W[i-1] = W[i-2] + (i-1) * T[i];
    }
    int n;
    cin >> n;
    int m;
    while (n--)
    {
        cin >> m;
        cout << W[m] << "\n";
    }
}