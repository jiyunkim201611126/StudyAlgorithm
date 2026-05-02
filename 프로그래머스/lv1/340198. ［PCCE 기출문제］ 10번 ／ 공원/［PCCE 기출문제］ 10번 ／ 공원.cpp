#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    
    vector<vector<int>> dp(park.size(), vector<int>(park[0].size(), 0));
    int maxSize = 0;
    
    // 현재 칸을 오른쪽 아래 꼭짓점으로 하는 정사각형의 크기를 기록합니다.
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            // 현 위치가 빈 칸인 경우 들어가는 분기입니다.
            if (park[i][j] == "-1")
            {
                // 가장 윗줄, 가장 왼쪽줄은 사이즈 1짜리 정사각형으로 기록합니다.
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 1;
                    if (maxSize < dp[i][j])
                    {
                        maxSize = dp[i][j];
                    }
                    continue;
                }
                
                // 왼쪽위로 주변 3칸에 기록해둔 정사각형 크기 + 1 중 가장 작은 값을 기록합니다.
                // 이 값이 현재 칸을 오른쪽 아래 꼭짓점으로 하는 정사각형의 크기입니다.
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                if (maxSize < dp[i][j])
                {
                    maxSize = dp[i][j];
                }
            }
        }
    }
    
    for (int mat : mats)
    {
        if (mat <= maxSize && answer < mat)
        {
            answer = mat;
        }
    }
    
    return answer;
}