#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    // 이름과 점수를 매핑합니다.
    unordered_map<string, int> nameToYearning;
    for (int i = 0; i < name.size(); ++i)
    {
        nameToYearning.emplace(name[i], yearning[i]);
    }
    
    // 사진에 따라 점수를 매긴 후 저장합니다.
    for (int i = 0; i < photo.size(); ++i)
    {
        int score = 0;
        for (int j = 0; j < photo[i].size(); ++j)
        {
            score += nameToYearning[photo[i][j]];
        }
        answer.push_back(score);
    }
    
    return answer;
}