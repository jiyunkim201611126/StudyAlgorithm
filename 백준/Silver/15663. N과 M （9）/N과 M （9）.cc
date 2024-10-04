#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int input[8];
int answer[8];
bool check[8];

void recur(int cnt)
{
    // 이번이 m번째 진입이면 답 출력 후 return
    if (cnt == m)
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // 중복 수열 경우를 거르기 위해 temp 사용
    int temp = 0;

    // m번째 진입이 아닌 경우
    for (int i = 0; i < n; i++)
    {
        // 이번 원소를 쓴 적이 없고, 해당 값이 이번 순서에 온 적이 없을 때
        if (!check[i] && temp != input[i])
        {
            answer[cnt] = input[i];
            temp = input[i];
            check[i] = true;
            recur(cnt + 1);
            check[i] = false;
        }
    }
    return;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    // 정렬
    sort(input, input + n);

    recur(0);

    return 0;
}