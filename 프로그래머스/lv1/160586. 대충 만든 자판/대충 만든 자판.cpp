#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    // 어떤 문자를 입력하기 위해 최소 몇 번의 입력을 수행해야 하는지 기록하는 map입니다.
    unordered_map<char, int> keyToNumber;
    
    for (const string& keys : keymap)
    {
        for (int i = 0; i < keys.size(); ++i)
        {
            char currentKey = keys[i];
            
            // currentKey에 해당하는 값이 없다면 새로 넣고, 있다면 값을 비교해 작은 값으로 재할당합니다.
            auto It = keyToNumber.find(currentKey);
            if (It == keyToNumber.end())
            {
                keyToNumber[currentKey] = i + 1;
            }
            else
            {
                It->second = std::min(It->second, i + 1);
            }
        }
    }
    
    // target 문자들의 최소 입력값을 모두 더해 결괏값을 기록합니다.
    for (const string& target : targets)
    {
        int answerValue = 0;
        for (int i = 0; i < target.size(); ++i)
        {
            auto It = keyToNumber.find(target[i]);
            if (It == keyToNumber.end())
            {
                // 존재하지 않는 문자인 경우 -1을 할당하고 다음 target을 검사합니다.
                answerValue = -1;
                break;
            }
            answerValue += keyToNumber[target[i]];
        }
        answer.push_back(answerValue);
    }
    
    return answer;
}