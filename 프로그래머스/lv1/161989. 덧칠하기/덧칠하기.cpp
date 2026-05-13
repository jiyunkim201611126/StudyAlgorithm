#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    // 첫 반복문 진입 시 페인트칠 시작을 보장하기 위해 값을 -m으로 할당합니다.
    int lastPaintingStartedSection = -m;
    for (const int shouldPaint : section)
    {
        // 페인트칠을 한 끝 공간보다 더 우측 공간에 페인트칠을 해야 한다면 들어가는 분기입니다.
        if (lastPaintingStartedSection + m - 1 < shouldPaint)
        {
            // 페인트칠을 시작한 지점을 기록합니다.
            lastPaintingStartedSection = shouldPaint;
            
            // 페인트칠 횟수를 기록합니다.
            ++answer;
        }
    }
    
    return answer;
}