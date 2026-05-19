#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// DFS로 순회하며 가능한 모든 type 조합을 만듭니다.
void DFS(const vector<int>& types, int k, vector<int>& current, vector<vector<int>>& resultTypeComb)
{
    // '최대 행동 수 k'기 때문에, 행동 횟수가 k보다 적은 상황도 조합으로서 기록합니다.
    resultTypeComb.push_back(current);
    
    if (current.size() == k)
    {
        return;
    }
    
    for (int i = 0; i < types.size(); ++i)
    {
        // 직전에 고른 type과 같으면 스킵합니다.
        if (!current.empty() && current.back() == types[i])
        {
            continue;
        }
        
        current.push_back(types[i]);
        
        DFS(types, k, current, resultTypeComb);
        
        current.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    int answer = 0;
    
    // type, node, node 순으로 기록됩니다.
    vector<vector<vector<int>>> graph(4, vector<vector<int>>(n + 1));
    
    vector<int> types;
    vector<bool> hasType(4, false);
    
    for (const vector<int> edge : edges)
    {
        graph[edge[2]][edge[1]].push_back(edge[0]);
        graph[edge[2]][edge[0]].push_back(edge[1]);
        
        int type = edge[2];
        
        // 중복 없이 모든 type을 기록합니다. 사실 type이 1~3까지밖에 없어서 의미는 없습니다.
        if (!hasType[type])
        {
            hasType[type] = true;
            types.push_back(type);
        }
    }
    
    vector<int> current;
    vector<vector<int>> resultTypeComb;
    
    DFS(types, k, current, resultTypeComb);
    
    // 모든 type 조합을 순회합니다.
    for (const vector<int>& typeComb : resultTypeComb)
    {
        vector<int> infected;
        vector<bool> isInfected(n + 1, false);
        
        // 처음 감염된 노드를 추가한 상태로 시작합니다.
        infected.push_back(infection);
        isInfected[infection] = true;
        
        for (int i = 0; i < typeComb.size(); ++i)
        {
            int type = typeComb[i];
            
            for (int j = 0; j < infected.size(); ++j)
            {
                int node = infected[j];
                
                // 이번에 감염될 노드를 가져옵니다.
                const vector<int>& currentInfection = graph[type][node];
                
                // 중복 없이 infected vector에 추가합니다.
                for (int nextNode : currentInfection)
                {
                    if (isInfected[nextNode])
                    {
                        continue;
                    }
                    
                    isInfected[nextNode] = true;
                    infected.push_back(nextNode);
                }
            }
        }
        
        // 가장 높은 값을 선택합니다.
        answer = max(answer, (int)infected.size());
    }
    
    return answer;
}