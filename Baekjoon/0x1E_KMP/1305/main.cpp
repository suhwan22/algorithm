#include <iostream>
#include <string>
#include <vector>

std::vector<int> getPartialMatch(std::string& search);

int main()
{
  std::string input;
  int len;

  std::cin >> len;
  std::cin >> input;

  if (len == 1) {
        std::cout << 1;
        return 0;
  }
  auto pi = getPartialMatch(input);
  std::cout << len - pi[len - 1];
}

std::vector<int> getPartialMatch(std::string& search){
    int m = search.size();
    std::vector<int> pi(m, 0);
    
    int begin = 1, matched = 0;
    
    while(begin + matched < m){
        if(search[begin + matched] == search[matched]){
            matched++;
            pi[begin + matched - 1] = matched;
        }
        else{
            if(matched == 0)
                begin++;
            else{
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    
    return pi;
}