#include <iostream>
#define scanf scanf_s

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long L, R;
    cin >> L >> R;

    int resultCount = 0;
    while (true)
    {
        long long firstNumberOfL;
        long long firstNumberOfR;

        // 1의 자릿수 구해오기
        firstNumberOfL = L % 10;
        firstNumberOfR = R % 10;

        // 1의 자릿수 버리고 한 칸씩 땡기기
        L /= 10;
        R /= 10;

        // 두 숫자의 자릿수가 다른 경우 8이 없는 숫자가 반드시 있으므로 0 출력
        if ((L != 0 && R == 0) || (L == 0 && R != 0))
        {
            resultCount = 0;
            break;
        }

        // 서로 다른 숫자인 경우 지금까지 구한 resultCount가 무의미하므로 초기화
        if (firstNumberOfL != firstNumberOfR)
        {
            resultCount = 0;
        }

        // 10으로 나눈 나머지가 8인 경우 
        if (firstNumberOfL == 8 && firstNumberOfR == 8)
        {
            ++resultCount;
            continue;
        }

        // 더이상 나눌 수 없는 경우 반복문을 빠져나갑니다.
        if (L == 0 && R == 0)
        {
            break;
        }
    }

    cout << resultCount << "\n";

    return 0;
}