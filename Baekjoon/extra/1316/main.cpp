/*
 * Author      : suhwan22
 * Email       : ksuhwan22@gmail.com
 * GitHub      : https://github.com/suhwan22
 * Additional  : https://guiltless-break-8cc.notion.site/boj
 * Created     : 2025-04-17 22:20:37
 * Updated     : 2025-04-17 22:25:27
 */

#include <iostream>
#include <cstring>

using namespace std;

int n, cnt;
bool visited[26];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        bzero(visited, sizeof(visited));
        bool flag = true;
        cin >> input;
        visited[input[0] - 'a'] = true;
        for (int j = 1; j < (int)input.size(); j++)
				{
					if (!(visited[input[j] - 'a'] == 0 || input[j - 1] == input[j]))
						flag = false;
					else
						visited[input[j] - 'a'] = true;
				}
        if (flag)
          cnt++;
    }
    cout << cnt;
}