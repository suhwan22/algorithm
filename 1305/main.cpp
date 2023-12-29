#include <iostream>
#include <string>

using namespace std;

int main()
{
    int len;
    string input;
    
    cin >> len;
    cin >> input;
    
    if (len == 1) {
        cout << 1;
        return 0;
    }
    
    int min = 1;
    
    for (int i = 1, j = 0; i < len; i++, j++) {
        if (j >= min)
            j = 0;
        if (input[j] == input[i]) {
          continue ;
        }
        else {
          if (i + 1 >= len / 2) {
            i = min;
            min++;
            j = -1;
          }
          else {
            j = -1;
            min = i + 1;
          }
        }
    }
    cout << min;
    return 0;
}