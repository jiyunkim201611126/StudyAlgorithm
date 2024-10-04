#include <iostream>
#include <queue>

using namespace std;

// 우선순위 큐, Heap으로 구성되어있으며 조건은 오름차순이다.
// 작은 숫자부터 pop된다.
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 연산의 개수
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int input;

        cin >> input;

        if (input) // 0이 아닌 값이면 true
        {
            pq.push(input);
        }
        else
        {
            if (pq.empty())
            {
                // pq가 비어있으면
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}