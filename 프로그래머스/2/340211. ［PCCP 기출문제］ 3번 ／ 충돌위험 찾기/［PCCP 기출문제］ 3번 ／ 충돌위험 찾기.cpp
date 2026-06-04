#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    // 주어진 경로를 풀기 좋게 정리합니다.
    map<vector<int>, int> pointToRobot;
    vector<vector<int>> currentPoints;
    vector<vector<int>> targetPointIndices;
    for (const vector<int>& route : routes)
    {
        vector<int> currentPoint = points[route[0] - 1];
        currentPoints.push_back(currentPoint);
        ++pointToRobot[currentPoint];
        vector<int> targets(route.begin() + 1, route.end());
        targetPointIndices.push_back(targets);
    }
    
    while (pointToRobot.size() > 0)
    {
        // 현재 좌표당 로봇 수를 검사해 2개 이상 위치해있다면 위험 카운트를 증가시킵니다.
        for (const auto& pair : pointToRobot)
        {
            if (pair.second > 1)
            {
                ++answer;
            }
        }
        
        for (int i = 0; i < currentPoints.size(); ++i)
        {
            if (targetPointIndices[i].size() == 0)
            {
                // 목적지가 더 없다면 로봇을 움직이지 않습니다.
                continue;
            }
            
            // 현재 위치에 기록된 로봇 카운트를 1 감소시킵니다.
            --pointToRobot[currentPoints[i]];
            
            vector<int> currentTargetPoint = points[targetPointIndices[i][0] - 1];
            if (currentPoints[i] == currentTargetPoint)
            {
                // 현재 목적지에 도달했다면 다음 목적지를 확인할 수 있도록 0번째 targetPoints를 제거합니다.
                targetPointIndices[i].erase(targetPointIndices[i].begin());
                
                if (targetPointIndices[i].size() == 0)
                {
                    continue;
                }
                
                // 목적지를 갱신합니다.
                currentTargetPoint = points[targetPointIndices[i][0] - 1];
            }
            
            // 로봇을 이동시킵니다.
            if (currentPoints[i][0] != currentTargetPoint[0])
            {
                currentPoints[i][0] < currentTargetPoint[0] ? ++currentPoints[i][0] : --currentPoints[i][0];
                
            }
            else if (currentPoints[i][1] != currentTargetPoint[1])
            {
                currentPoints[i][1] < currentTargetPoint[1] ? ++currentPoints[i][1] : --currentPoints[i][1];
            }
            
            // 현재 위치에 로봇 카운트를 1 증가시킵니다.
            ++pointToRobot[currentPoints[i]];
        }
        
        for (auto it = pointToRobot.begin(); it != pointToRobot.end();)
        {
            if (it->second == 0)
            {
                it = pointToRobot.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
    
    return answer;
}