#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(edge.size() + 1);
    
    for (int i = 0; i < edge.size(); i++)
    {
        int a = edge[i][0];
        int b = edge[i][1];
        
        // a와 b 노드는 연결되어 있음.
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    // -1은 방문하지 않았다는 의미입니다.
    vector<int> distance(graph.size(), -1);
    queue<int> q;
    
    // 1번 노드부터 시작하므로 일단 1을 푸쉬하고 시작합니다.
    distance[1] = 0;
    q.push(1);
    
    int maxDistance = 0;
    
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            
            // 이미 방문한 노드라면 스킵합니다.
            if (distance[next] != -1)
            {
                continue;
            }
            
            // 현재 방문 상태인 노드의 거리에 1 더한 값을 다음 노드의 거리로 할당합니다.
            distance[next] = distance[current] + 1;
            
            // 거리가 현재까지 기록된 maxDistance보다 크다면 maxDistance에 할당합니다.
            if (maxDistance < distance[next])
            {
                maxDistance = distance[next];
            }
            
            // 다음 방문할 노드를 기록합니다.
            q.push(next);
        }
    }
    
    // 가장 멀리 떨어진 노드의 개수를 기록합니다.
    for (int i = 0; i < distance.size(); i++)
    {
        if (distance[i] == maxDistance)
        {
            answer++;
        }
    }
    
    return answer;
}