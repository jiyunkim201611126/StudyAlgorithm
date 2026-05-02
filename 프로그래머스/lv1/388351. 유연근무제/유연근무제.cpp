#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for (int i = 0; i < timelogs.size(); i++)
    {
        bool bsuccess = true;
        for (int j = 0; j < timelogs[i].size(); j++)
        {
            // 토요일, 일요일은 스킵합니다.
            int currentday = (startday + j - 1) % 7 + 1;
            if (currentday == 6 || currentday == 7)
            {
                continue;
            }
            
            // 모든 시간을 분으로 환산합니다.
            int targetminute = (schedules[i] / 100 * 60) + (schedules[i] % 100);
            int sourceminute = (timelogs[i][j] / 100 * 60) + (timelogs[i][j] % 100);
            
            // 출근 희망 시간 + 10분보다 늦게 출근했다면 실패로 기록합니다.
            if (sourceminute > targetminute + 10)
            {
                bsuccess = false;
                break;
            }
        }
        
        if (bsuccess)
        {
            answer++;
        }
    }
    
    return answer;
}