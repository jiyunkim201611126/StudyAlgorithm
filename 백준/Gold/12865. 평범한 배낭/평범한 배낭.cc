#include <iostream>
using namespace std;

// github commit test

int weight[101];
int value[101];
// dp는 최대 가치(value)를 값으로 가짐
int dp[101][100001];

int main() {

    int n, k;
    cin >> n >> k;

    // n개 물건의 무게와 가치 입력
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    
    // i는 물건의 순서, j는 최대 무게
    // 최대 무게가 1이라고 가정, k까지 순차적으로 늘려가며 확인
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j >= weight[i])
            {
                // 현재 확인 중인 물건의 무게가 최대 무게를 넘지 않는 경우
                // 바로 전 물건까지 확인한 최대 가치,
                // (현재 최대 무게 - 현재 물건 무게)의 최대 가치 + 현재 물건 가치
                // 둘 중 큰 것을 dp[i][j]에 담음
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
            else
                // 최대 무게를 넘어 넣을 수 없는 경우
                // 바로 전 물건까지 확인한 최대 가치를 dp[i][j]에 담음
                dp[i][j] = dp[i - 1][j];
        }
    }

    cout << dp[n][k];

    return 0;
}