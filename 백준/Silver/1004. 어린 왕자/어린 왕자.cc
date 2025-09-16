#include <iostream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int x1, y1, x2, y2;
        int n;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;

        int result = 0;

        for (int j = 0; j < n; ++j)
        {
            /*
            * 행성계가 출발점과 도착점 중 하나만 감싸고 있는 경우에만 진입/이탈하게 됩니다.
            * 따라서 행성계의 중앙으로부터 출발점과 도착점까지의 거리를 구하고, 해당 거리가 반지름보다 하나만 짧은 경우를 구하면 됩니다.
            */

            int cx, cy, r;
            cin >> cx >> cy >> r;

            int radiusSquared = r * r;

            int firstDistOfX = abs(x1 - cx);
            int firstDistOfY = abs(y1 - cy);
            int firstDistSquared = firstDistOfX * firstDistOfX + firstDistOfY * firstDistOfY;

            int secondDistOfX = abs(x2 - cx);
            int secondDistOfY = abs(y2 - cy);
            int secondDistSquared = secondDistOfX * secondDistOfX + secondDistOfY * secondDistOfY;

            bool firstPointIsInside = firstDistSquared < radiusSquared;
            bool secondPointIsInside = secondDistSquared < radiusSquared;

            if (firstPointIsInside ^ secondPointIsInside)
            {
                ++result;
            }
        }

        cout << result << '\n';
    }

    return 0;
}