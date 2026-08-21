#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 점을 직접 찍으면서 개수를 세는 방식보다는, 상하좌우 대칭이므로 우상단 하나만 구한 뒤 * 4 하는 식으로 구합니다.
long long solution(int r1, int r2) {
    long long answer = 0;
    // 반지름의 제곱을 계산합니다.
    long long R1 = 1LL * r1 * r1;
    long long R2 = 1LL * r2 * r2;
    
    for (long long x = 1; x <= r2; ++x)
    {
        // 바깥 원 안에 들어오는 가장 큰 y를 계산합니다.
        long long maxY = floor(sqrt((long double)(R2 - x * x)));
        
        // 작은 원 내부에 포함되지 않는 가장 작은 y를 계산합니다.
        long long minY = 0;
        if (x < r1)
        {
            minY = ceil(sqrt((long double)(R1 - x * x)));
        }
        
        // 현재 x에서 가능한 y의 개수를 계산합니다.
        answer += maxY - minY + 1;
    }
    
    return answer * 4;
}