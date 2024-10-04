#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, c;

// 아래는 분할 정복 알고리즘이다.
// 큰 문제를 여러 개의 작은 문제로 나누어 구하는 문제 해결 방법이다.
// a^b % c는 (a^(b / 2) % c * a^(b / 2) % c) % c 로 구할 수 있겠다. (b가 홀수면 하나는 b / 2 + 1)
// 이 과정을 재귀 함수로 구현해보자.
long long recur(long long x)
{
    if (x == 0)
        return 1;
    else if (x == 1)
        return a % c;

    long long val = recur(x / 2) % c;

    if (x % 2 == 0)
        return val * val % c;
    else
        return (val * val % c) * (a % c);
}

int main() {

    cin >> a >> b >> c;

    cout << recur(b) % c;

    // 아래 방법은 수가 너무 커지면서 성능 저하가 발생, 시간 내로 해결 불가능
    // cout << pow(a, b) % c;

    return 0;
}