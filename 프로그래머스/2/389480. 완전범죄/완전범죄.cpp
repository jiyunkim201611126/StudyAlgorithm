#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> info, int n, int m) {
    const int INF = 10000000;
    
    // dp[b]란 B 흔적이 b일 때, 가능한 A 흔적의 최소값을 의미합니다.
    vector<int> dp(m, INF);
    dp[0] = 0;
    
    for (auto& item : info)
    {
        int aTrace = item[0];
        int bTrace = item[1];
        
        vector<int> next(m, INF);
        
        for (int b = 0; b < m; ++b)
        {
            // B의 흔적이 사실상 존재할 수 없는 값이라면 스킵합니다.
            if (dp[b] == INF)
            {
                continue;
            }
            
            // 이번에 A가 훔친 경우에 대해 계산합니다.
            int newA = dp[b] + aTrace;
            if (newA < n)
            {
                next[b] = min(next[b], newA);
            }
            
            // 이번에 B가 훔친 경우에 대해 계산합니다.
            int newB = b + bTrace;
            if (newB < m)
            {
                next[newB] = min(next[newB], dp[b]);
            }
        }
        
        // dp를 next로 덮어씌웁니다.
        // 즉, dp는 '이전 물건까지 처리한 상태'를 나타내고, next는 '이번 물건까지 처리한 상태'가 됩니다.
        // 이를 통해 흔적 최대치를 초과한 경우는 자연스럽게 버려집니다.
        dp = next;
    }
    
    
    int answer = *min_element(dp.begin(), dp.end());
    return answer == INF ? -1 : answer;
}