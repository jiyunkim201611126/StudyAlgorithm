#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    // 증설된 서버의 남은 시간을 나타냅니다.
    vector<int> serverTime;
    
    // 서버가 추가된 횟수를 나타냅니다.
    int addedCount = 0;
    
    for (int i = 0; i < players.size(); ++i)
    {
        // 증설해야 하는 서버 개수를 계산합니다.
        int shouldAddCount = players[i] / m;
        
        // 현재 증설된 서버 개수를 가져옵니다.
        int currentAddedCount = serverTime.size();
        
        // 실제 필요한 서버 개수를 꼐산합니다.
        int actualNeedCount = shouldAddCount - currentAddedCount;
        
        if (actualNeedCount > 0)
        {
            for (int j = 0; j < actualNeedCount; ++j)
            {
                serverTime.push_back(k);
                ++addedCount;
            }
        }
        
        // 1시간이 지났음을 기록합니다.
        for (int k = 0; k < serverTime.size(); ++k)
        {
            --serverTime[k];
        }
        
        // 시간이 남지 않은 서버는 제거합니다.
        serverTime.erase(
        remove_if(serverTime.begin(), serverTime.end(),
                  [](int time)
                  {
                      return time <= 0;
                  }),
            serverTime.end()
            );
    }
    
    answer = addedCount;
    return answer;
}