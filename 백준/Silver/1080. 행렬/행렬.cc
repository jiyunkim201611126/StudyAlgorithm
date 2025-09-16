#include <iostream>

using namespace std;

/*
* 최솟값을 구하라고 해서 조금 헷갈렸는데, 사실 이는 말장난이다.
* 두 행렬의 원소를 비교해 다르면 어쨌든 뒤집어야 하고, 이는 필연적으로 다른 원소에게 영향을 줄 수밖에 없다.
* 그런데 모서리에 붙어있는 원소는 뒤집어야 하는 방향이 정해져있다.
* 좌측 최상단 원소가 달라서 우하단에 영향을 주며 뒤집었을 때, 그렇게 영향을 받은 우하단의 원소가 달라졌을 경우
* 좌상단에 영향을 주며 뒤집으면 원래대로 돌아가니, 어차피 좌상단에 영향을 주며 뒤집진 못 한다.
* 따라서 좌측 최상단부터 출발해 우하단에 영향을 주는 뒤집기로 계속 뒤집으면 결과적으로 행렬이 같아지며, 그게 최솟값이다.
*/

int first[50][50];
int second[50][50];

int main() {

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &first[i][j]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%1d", &second[i][j]);
        }
    }

    int result = 0;

    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = 0; j < m - 2; ++j)
        {
            if (first[i][j] != second[i][j])
            {
                for (int k = i; k <= i + 2; ++k)
                {
                    for (int l = j; l <= j + 2; ++l)
                    {
                        first[k][l] = 1 - first[k][l];
                    }
                }
                ++result;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (first[i][j] != second[i][j])
            {
                cout << -1;
                return 0;
            }
        }
    }

    cout << result << "\n";

    return 0;
}