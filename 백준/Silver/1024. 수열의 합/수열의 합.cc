#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long double N, L;
    cin >> N >> L;

    /*
    * 주어진 수를 x라 할 때, 길이가 L인 정수 리스트의 총합은 x + (x + 1) + (x + 2) + ... + (x + (L - 1)) 로 표현할 수 있다.
    * N = Lx + 1 + 2 + 3 + ... + (L - 1)로 바꿔주고
    * 방정식으로 x의 식을 만들어보면
    * Lx = N - 상수합
    * x = (N - 상수합) / L 이 된다.
    * 상수합은 1 ~ L - 1 까지 모두 더한 값이므로, 이제 N과 L을 통해 x를 유추할 수 있다.
    * 단, 양의 정수만으로 합산해야 하기 때문에 x는 음수가 될 수 없다.
    */

    // 길이는 2 ~ 100
    for (L; L <= 100; ++L)
    {
        long double sum = 0;
        for (int i = 1; i < L; ++i)
        {
            sum += i;
        }

        long double x = (N - sum) / L;

        if (x >= 0 && (int)x == x)
        {
            for (int i = 0; i < L; ++i)
            {
                cout << (int)(x + i) << " ";
            }
            return 0;
        }
    }

    cout << -1;

    return 0;
}