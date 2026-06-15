#include <string>
#include <vector>

using namespace std;

int GetTimeToSecond(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

/** 모든 시간을 초로 환산한 값을 인자로 받아 위치를 반환하는 함수입니다. */
int GetHourPos(int t)
{
    return t % 43200;
}

int GetMinutePos(int t)
{
    return t * 12 % 43200;
}

int GetSecondPos(int t)
{
    return t * 720 % 43200;
}

/** 시작 시점에 겹쳤는지 확인하는 함수입니다. */
bool IsOverlapAt(int t)
{
    int h = GetHourPos(t);
    int m = GetMinutePos(t);
    int s = GetSecondPos(t);
    
    return s == h || s == m;
}

/** 현재 초침과 다음 초침 위치 사이에 매개변수로 들어온 다른 침이 있는지 확인하는 함수입니다. */
bool IsCross(int currentS, int nextS, int currentOtherHand, int nextOtherHand)
{
    // 계산이 꼬이지 않도록 '다음 위치'가 정확히 시계 기준 12를 가리키면 43200으로 바꿔줍니다.
    if (nextS == 0)
    {
        nextS = 43200;
    }
    if (nextOtherHand == 0)
    {
        nextOtherHand = 43200;
    }
    
    return currentS < currentOtherHand && nextOtherHand <= nextS;
}

/**
 * 초침이 12바퀴를 돌면 1분, 720바퀴를 돌면 1시간입니다.
 * 따라서 초침의 1초당 이동량을 1이라 하면, 분침은 1/12, 시침은 1/720 움직입니다.
 * 이렇게 하면 계산하기가 불편하므로, 1초당 이동량을 각각 720, 12, 1로 잡습니다.
 * 실제 위치는 12시간까지 표시된 시계를 빙빙 돌기 때문에, 43200(하루가 86400초니까)으로 나눈 나머지로 표현합니다.
 * 답은 겹쳤는지를 시작할 때 확인해 카운트, 현재 초침과 다음 초침 위치 사이에 분침이나 시침이 있는지를 카운트합니다.
 */
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    
    int start = GetTimeToSecond(h1, m1, s1);
    int end = GetTimeToSecond(h2, m2, s2);
    
    if (IsOverlapAt(start))
    {
        // 시작 시점에 겹쳐있으면 카운트합니다.
        ++answer;
    }
    
    for (int time = start; time < end; ++time)
    {
        int currentH = GetHourPos(time);
        int currentM = GetMinutePos(time);
        int currentS = GetSecondPos(time);
        int nextH = GetHourPos(time + 1);
        int nextM = GetMinutePos(time + 1);
        int nextS = GetSecondPos(time + 1);
        
        bool crossHour = IsCross(currentS, nextS, currentH, nextH);
        bool crossMinute = IsCross(currentS, nextS, currentM, nextM);
        
        if (crossHour)
        {
            ++answer;
        }
        if (crossMinute)
        {
            ++answer;
        }
        if (crossHour && crossMinute && nextH == nextM)
        {
            // 시침과 분침이 정확하게 겹친 경우는 제외합니다.
            --answer;
        }
    }
    
    return answer;
}