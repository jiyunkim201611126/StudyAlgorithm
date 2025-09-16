#include <iostream>
#include <vector>

using namespace std;

vector<bool> checked;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int friends[50][50];

    cin >> N;

    /*
    * 2차원 배열을 통해 그래프를 만들어 DFS로 해결할 수 있는 문제입니다.
    * 행에서 Y인 인덱스를 찾고, Y번째 행으로 가서 Y의 개수를 세면 2-친구의 값을 구할 수 있습니다.
    * 단, 중복된 인원은 카운트하지 말아야 합니다.
    */

    // 먼저 2차원 배열을 초기화합니다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            friends[i][j] = 0;
        }
    }

    // Y를 입력받은 경우 1을 할당합니다.
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            char c;
            cin >> c;
            if (c == 'Y')
            {
                friends[i][j] = 1;
            }
        }
    }

    checked = vector<bool>(N, false);

    // 2-친구의 최댓값을 탐색합니다.
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int l = 0; l < N; ++l)
        {
            checked[l] = false;
        }

        checked[i] = true;

        int tempResult = 0;
        for (int j = 0; j < N; ++j)
        {
            if (friends[i][j] == 1)
            {
                if (!checked[j])
                {
                    checked[j] = true;
                    ++tempResult;
                }

                for (int k = 0; k < N; ++k)
                {
                    if (!checked[k] && friends[j][k] == 1)
                    {
                        checked[k] = true;
                        ++tempResult;
                    }
                }
            }
            if (tempResult > result)
            {
                result = tempResult;
            }
        }
    }

    cout << result;

    return 0;
}