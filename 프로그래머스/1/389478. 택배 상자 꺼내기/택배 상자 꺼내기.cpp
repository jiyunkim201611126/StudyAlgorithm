#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    // 층 수를 먼저 계산합니다.
    int MaxFloor = (n + w - 1) / w;
    
    // 정리된 박스 상자를 표현할 2차원 배열을 선언합니다.
    vector<vector<int>> BoxStacks(MaxFloor, vector<int>(w, 0));
    
    int TargetRow = 0;
    for (int Index = 1; Index <= n; Index++)
    {
        // 현재 층과 이번 층의 몇 번째 인덱스로 들어갈지 계산합니다.
        int CurrentFloor = (Index - 1) / w;
        int IndexInRow = (Index - 1) % w;
        
        bool bIsRight = (CurrentFloor % 2) == 0;
        
        if (bIsRight)
        {
            // 홀수층이면 IndexInRow 그대로 넣습니다.
            BoxStacks[CurrentFloor][IndexInRow] = Index;
            if (Index == num)
            {
                TargetRow = IndexInRow;
            }
        }
        else
        {
            // 짝수층이면 IndexInRow를 뒤집어서 넣습니다.
            BoxStacks[CurrentFloor][w - IndexInRow - 1] = Index;
            if (Index == num)
            {
                TargetRow = w - IndexInRow - 1;
            }
        }
    }
    
    for (int Index = MaxFloor - 1; Index >= 0; Index--)
    {
        if (BoxStacks[Index][TargetRow] != 0)
        {
            answer++;
        }
        if (BoxStacks[Index][TargetRow] == num)
        {
            break;
        }
    }
    
    return answer;
}