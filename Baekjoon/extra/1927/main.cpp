#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    int input;
    while (n--)
    {
        cin >> input;
        if (input == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else
                cout << "0\n";
        }
        else
            pq.push(input);
    }
    
    return 0;
}
