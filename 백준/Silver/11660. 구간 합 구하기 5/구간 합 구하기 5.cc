#include <iostream>

using namespace std;

int n, m;
int arr[1026][1026];
int dp[1026][1026];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 입력과 동시에 해당 위치까지 총합 구하기
            // 총합이란 (1, 1)부터 (i, j)까지 영역의 합을 의미한다.
            cin >> arr[i][j];
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // (2, 2)부터 (3, 3)까지 영역의 합을 구하는 예시를 들어보면
        // 1 1 1      0 0 0      -1 0 0      0 0 0
        // 1 1 1  ->  1 1 1  ->   0 1 1  ->  0 1 1
        // 1 1 1      1 1 1       0 1 1      0 1 1
        // 이와 같은 순서로 계산해 구해주면 된다.
        // 아래는 이를 구현한 식이다.
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
    }
    
    return 0;
}