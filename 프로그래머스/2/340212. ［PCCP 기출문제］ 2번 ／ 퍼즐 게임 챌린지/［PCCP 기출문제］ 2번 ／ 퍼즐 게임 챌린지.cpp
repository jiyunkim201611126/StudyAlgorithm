#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool CanSolve(const vector<int>& diffs, const vector<int>& times, long long limit, int level)
{
    long long total = 0;
    
    for (int i = 0; i < diffs.size(); ++i)
    {
        int diff = diffs[i];
        int timeCurrent = times[i];
        int timePrevious = (i == 0) ? 0 : times[i - 1];
        
        // 난이도와 숙련도에 따른 총 소요 시간을 계산합니다.
        if (diff <= level)
        {
            total += timeCurrent;
        }
        else
        {
            long long retryCount = diff - level;
            total += retryCount * (timeCurrent + timePrevious) + timeCurrent;
        }
        
        // 이미 제한시간을 초과했다면 더 볼 필요 없이 false를 반환합니다.
        if (total > limit)
        {
            return false;
        }
    }
    
    return total <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    // 이분 탐색을 위한 변수들을 선언합니다.
    int left = 1;
    
    // 숙련도가 모든 문제의 난이도보다 높다면 한 번에 풀 수 있기 때문에, 최고 난이도가 숙련도 최솟값의 상한선이 됩니다.
    int right = *max_element(diffs.begin(), diffs.end());
    int answer = right;
    
    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (CanSolve(diffs, times, limit, mid))
        {
            // mid로 가능하다면 더 낮은 숙련도로 가능한지 확인합니다.
            answer = mid;
            right = mid - 1;
        }
        else
        {
            // mid로 불가능하다면 숙련도를 올려서 시도합니다.
            left = mid + 1;
        }
    }
    
    return answer;
}