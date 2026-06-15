#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 왼쪽부터 쭉 미사일을 훑어보다가, 한 미사일이 끝나는 지점을 마주치면 지금까지 훑은 미사일을 모두 제거하며 1 카운트합니다.
 * 이 방법을 사용하면 최소한의 요격으로 모든 미사일을 제거할 수 있습니다.
 */
int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    // 시간 복잡도를 줄이기 위해 먼저 e 기준으로 정렬합니다.
    // 미사일이 빨리 끝나는 순서대로 정렬된 상태입니다.
    sort(targets.begin(), targets.end(), 
        [](const auto& a, const auto& b)
        {
            return a[1] < b[1];
        });
    
    int lastShot = -1;
    
    for (const auto& target : targets)
    {
        int s = target[0];
        int e = target[1];
        
        // 마지막으로 요격한 위치보다 미사일 시작 위치가 더 오른쪽이라면 요격합니다.
        // >= 인 이유는, 해당 위치에 요격 시 끝에 걸린 미사일은 요격되지 않는다는 조건이기 때문에
        // 직전 요격에서 해당 미사일이 살아남았기 때문입니다.
        if (s >= lastShot)
        {
            ++answer;
            lastShot = e;
        }
    }
    
    return answer;
}