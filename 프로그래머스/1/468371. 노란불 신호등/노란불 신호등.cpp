#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 최대공약수를 구하는 함수입니다.
int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    
    return a;
}

// 최소공배수를 구하는 함수입니다.
int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

int solution(vector<vector<int>> signals) {
    int answer = -1;
    
    // 각 신호등의 한 사이클 시간입니다.
    vector<int> cycle(signals.size(), 0);
    
    for (int i = 0; i < signals.size(); i++)
    {
        int cycleSeconds = 0;
        for (int j = 0; j < signals[i].size(); j++)
        {
            cycleSeconds += signals[i][j];
        }
        cycle[i] = cycleSeconds;
    }
    
    // 모든 cycle에 대해 최소공배수를 계산합니다.
    int lcm = cycle[0];
    for (int i = 1; i < cycle.size(); i++)
    {
        lcm = LCM(lcm, cycle[i]);
    }
    
    // 1초부터 lcm초까지 순회하며 모든 신호가 노란불인 경우를 탐색합니다.
    for (int time = 1; time <= lcm; time++)
    {
        bool allYellow = true;
        
        for (int i = 0; i < signals.size(); i++)
        {
            int G = signals[i][0];
            int Y = signals[i][1];
            
            // 현재 초를 cycle 내로 재해석합니다.
            int pos = (time - 1) % cycle[i] + 1;
            
            // 하나라도 노란색이 아닌 신호가 있다면 현재 초에 대해 false로 기록하고 반복문을 빠져나갑니다.
            if (!(G < pos && pos <= G + Y))
            {
                allYellow = false;
                break;
            }
        }
        
        // 모두 노란색인 시간을 찾았다면 반환합니다.
        if (allYellow)
        {
            answer = time;
            break;
        }
    }
    
    return answer;
}