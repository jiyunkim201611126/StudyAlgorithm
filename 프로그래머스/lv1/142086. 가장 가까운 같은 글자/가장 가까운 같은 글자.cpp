#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map<char, int> charToNumber;
    for (int i = 0; i < s.size(); ++i)
    {
        auto It = charToNumber.find(s[i]);
        
        if (It == charToNumber.end())
        {
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - It->second);
        }
        
        charToNumber[s[i]] = i;
    }
    
    return answer;
}