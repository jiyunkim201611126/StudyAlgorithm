#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int answer = 99999999;
    
    int stageCount = cost.size();
    int bundleCount = hint.size();
    
    // 비트마스크를 활용해 hint 조합을 모두 비교합니다.
    for (int mask = 0; mask < (1 << bundleCount); ++mask)
    {
        int total = 0;
        
        // 각 스테이지별 보유 힌트 개수를 담을 vector입니다.
        vector<int> hintCount(stageCount, 0);
        
        // 현재 조합에서 어떤 번들을 샀는지 확인합니다.
        for (int i = 0; i < bundleCount; ++i)
        {
            if (mask & (1 << i))
            {
                // 번들 가격을 기록합니다.
                total += hint[i][0];
                
                // 번들이 제공하는 힌트를 스테이지에 맞춰 기록합니다.
                for (int j = 1; j < hint[i].size(); ++j)
                {
                    int stageIndex = hint[i][j] - 1;
                    hintCount[stageIndex]++;
                }
            }
        }
        
        // 모든 스테이지를 순회합니다.
        for (int stage = 0; stage < stageCount; ++stage)
        {
            // 해당 스테이지의 사용 가능한 힌트 개수를 가져옵니다.
            int count = hintCount[stage];
            count = min(count, stageCount - 1);
            
            // 힌트를 사용했을 때 비용을 합산해 기록합니다.
            total += cost[stage][count];
        }
        
        // 가장 비용이 적은 경우를 기록합니다.
        answer = min(answer, total);
    }
    
    return answer;
}