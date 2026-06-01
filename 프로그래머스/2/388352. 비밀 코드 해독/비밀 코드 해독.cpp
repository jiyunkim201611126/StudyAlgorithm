#include <string>
#include <vector>

using namespace std;

int ANSWER = 0;

void DFS(vector<int>& candidateCode, vector<vector<int>>& q, vector<int> ans, int start, int n)
{
    // 비밀 코드 후보가 완성됐다면 검사해봅니다.
    if (candidateCode.size() == 5)
    {
        // 입력한 숫자 조합을 순회합니다.
        for (int i = 0; i < q.size(); ++i)
        {
            // 입력한 숫자 조합과 비밀 코드 후보를 비교해서 몇 개가 들어맞았는지 확인합니다.
            int count = 0;
            for (int number : candidateCode)
            {
                for (int inputNumber : q[i])
                {
                    if (number == inputNumber)
                    {
                        ++count;
                        break;
                    }
                }
            }
            
            // 들어맞은 개수가 기록된 수와 일치하지 않으면 함수를 빠져나갑니다.
            if (count != ans[i])
            {
                return;
            }
        }
        
        // 들어맞은 개수가 기록된 수와 모두 일치하면 이를 기록합니다.
        ++ANSWER;
        return;
    }
    
    // 숫자 조합 5개가 완성될 수 있도록 오름차순으로 하나씩 넣어봅니다.
    for (int num = start; num <= n; ++num)
    {
        candidateCode.push_back(num);
        DFS(candidateCode, q, ans, num + 1, n);
        candidateCode.pop_back();
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    
    vector<int> candidateCode;
    
    DFS(candidateCode, q, ans, 1, n);
    
    answer = ANSWER;
    
    return answer;
}