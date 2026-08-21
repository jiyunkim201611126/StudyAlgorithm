#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    // 길이가 가장 짧은 수열을 찾아야 하므로 불가능하게 긴 길이의 숫자로 먼저 넣어둡니다.
    vector<int> answer = {0, 10000000};
    
    int leftIndex = 0;
    int rightIndex = 0;
    int sum = 0;
    
    // sequence를 모두 순회합니다.
    for (int i = 0; i < sequence.size(); ++i)
    {
        // 이번에 조회 중인 숫자를 sum에 더합니다.
        rightIndex = i;
        sum += sequence[rightIndex];
        
        // 합산된 값이 k를 넘었다면 왼쪽부터 sum에서 뺍니다.
        while (sum > k)
        {
            sum -= sequence[leftIndex];
            ++leftIndex;
        }
        
        // 합산된 값이 k와 일치한다면 수열의 길이를 비교해 짧은 쪽으로 기록합니다.
        // 길이가 같다면 먼저 발견한 구간을 유지해야 하기 때문에 <=가 아닌 <를 사용합니다.
        if (sum == k && (rightIndex - leftIndex < answer[1] - answer[0]))
        {
            answer = {leftIndex, rightIndex};
        }
    }
    
    return answer;
}