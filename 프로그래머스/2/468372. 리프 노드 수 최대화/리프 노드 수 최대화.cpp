#include <string>
#include <vector>

using namespace std;

/**
 * 사실상 트리 만들기 문제가 아니라 깊이별 분기 수를 2와 3 중 선택하는 문제입니다.
 * 중요한 부분은 split_limit보다 dist_limit입니다.
 * 2분기 후 3분기를 배치하는 것과 3분기 후 2분기를 배치하는 것 모두 분배도는 6으로 동일합니다.
 * 하지만 2분기를 먼저 배치하는 것이 더 적은 분배 노드를 사용하기 때문에, dist_limit면에서 효율적입니다.
 */

long long answer;
int distLimit;
int splitLimit;

/**
 * @cur 현재 깊이에서 "분배 노드로 쓰기로 예약"된 노드 개수
 * @usingDist 현재 사용 중인 분배 노드 개수
 * @splitScore 현재 깊이까지의 분배도
 * @fixedLeaf 이미 리프 노드로 확정된 노드 개수
 */
void DFS(long long cur, long long usingDist, long long splitScore, long long fixedLeaf, int previousChildCount)
{
    // 이번에 DFS를 멈추면 cur도 전부 리프 노드가 됩니다.
    answer = max(answer, fixedLeaf + cur);
    
    // 분배 노드 제한을 초과했다면 더이상 DFS를 돌지 않습니다.
    if (usingDist > distLimit)
    {
        return;
    }
    
    if (cur == 0)
    {
        return;
    }
    
    // 남은 사용 가능 분배 노드 개수를 계산합니다.
    long long remain = distLimit - usingDist;
    
    for (int childCount : {2, 3})
    {
        // 3 -> 2 순서로 분기하는 것은 2 -> 3 순서로 분기하는 것과 분배도, 리프 노드 개수가 동일합니다.
        // 하지만 3 -> 2 순서로 분기하는 게 분배 노드는 더 많이 소모하므로, 이미 3분기를 시도했다면 2분기를 더 계산할 필요가 없습니다.
        if (childCount < previousChildCount)
        {
            continue;
        }
        
        long long nextSplitScore = splitScore * childCount;
        if (nextSplitScore > splitLimit)
        {
            continue;
        }
        
        // 현재 cur개의 분배 노드가 childCount개씩 자식 노드를 생성합니다.
        long long createdCount = cur * childCount;
        
        // 다음 깊이에서 분배 노드로 쓸 수 있는 노드는 최대한 많이 예약합니다.
        // 같은 깊이에서 분기 수가 같다면, 몇개의 노드를 분기하든 splitScore는 동일합니다.
        // 또한 많이 예약한 상태는 나중에 멈추면 그대로 리프로 처리할 수 있으므로, 적게 예약하는 경우를 포함합니다.
        long long nextCur = min(createdCount, remain);
        
        // 예약하지 못 한 노드는 리프 노드로 확정합니다.
        long long nextFixedLeaf = fixedLeaf + (createdCount - nextCur);
        
        DFS(nextCur,
            usingDist + nextCur,
            nextSplitScore,
            nextFixedLeaf,
            childCount);
    }
}

int solution(int dist_limit, int split_limit) {
    answer = 1;
    distLimit = dist_limit;
    splitLimit = split_limit;
    
    DFS(1, 1, 1, 0, 2);
    
    return (int)answer;
}