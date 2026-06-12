#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    const int MAX_NODE = 1000000;
    
    // 간선이 들어가는 것과 나가는 것으로 정리해 그 개수를 담아둘 vector입니다.
    // (1,2) 간선이라면 1에서 나가고 2로 들어가는 간선이므로 outDegree[1]에 1을 더하고, inDegree[2]에 1을 더합니다.
    vector<int> inDegree(MAX_NODE + 1, 0);
    vector<int> outDegree(MAX_NODE + 1, 0);
    // 실제로 등장한 노드를 기록합니다.
    vector<bool> exists(MAX_NODE + 1, false);
    
    int maxNode = 0;
    
    // 모든 간선을 순회하며 해석합니다.
    for (const auto& edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        
        ++outDegree[from];
        ++inDegree[to];
        
        exists[from] = true;
        exists[to] = true;
        
        // 노드 중에서 가장 높은 숫자를 찾습니다.
        maxNode = max(maxNode, max(from, to));
    }
    
    // 만들어진 노드를 찾습니다.
    int created = 0;
    for (int node = 1; node <= maxNode; ++node)
    {
        if (!exists[node])
        {
            continue;
        }
        
        // 들어오는 간선은 없고 나가는 간선이 2개 이상이라면 만들어진 노드입니다.
        if (inDegree[node] == 0 && outDegree[node] >= 2)
        {
            created = node;
            break;
        }
    }
    
    // 만든 노드에서 각 그래프의 임의의 정점 하나로 향하는 간선을 만든다고 합니다.
    // 따라서 만들어진 노드에서 나가는 간선의 개수를 구하면 그게 모든 그래프 개수입니다.
    int totalGraphCount = outDegree[created];
    
    int barCount = 0;
    int eightCount = 0;
    
    // 모든 노드를 순회하며, 그래프의 특징을 통해 막대 모양 그래프 개수와 8자 모양 그래프의 개수를 구합니다.
    for (int node = 1; node <= maxNode; ++node)
    {
        if (!exists[node])
        {
            continue;
        }
        
        // 만들어진 노드는 스킵합니다.
        if (node == created)
        {
            continue;
        }
        
        if (outDegree[node] == 0)
        {
            // 막대 모양 그래프는 마지막 노드에 나가는 간선이 없습니다.
            ++barCount;
        }
        else if (outDegree[node] >= 2)
        {
            // 8자 모양 그래프는 교차하는 지점에서 나가는 간선이 2개 있습니다.
            ++eightCount;
        }
    }
    
    // 도넛 모양 그래프는 특징으로 개수를 구하기 애매합니다.
    // 모든 그래프 개수에서 막대 모양 그래프와 8자 모양 그래프의 개수를 빼는 것으로 계산합니다.
    int donutCount = totalGraphCount - barCount - eightCount;
    
    vector<int> answer;
    answer.push_back(created);
    answer.push_back(donutCount);
    answer.push_back(barCount);
    answer.push_back(eightCount);
    return answer;
}