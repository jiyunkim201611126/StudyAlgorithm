#include <iostream>

using namespace std;

int colorPaper[129][129] = { 0, };
int answer[2] = { 0, 0 };

void recur(int column, int row, int length) {
    
    if (length == 1) // 1칸까지 잘라진 경우
    {
        answer[colorPaper[column][row]]++;
        return;
    }

    int check = 0;
    int color = colorPaper[column][row]; // 가장 처음 칸 무슨 색인지 기록
    
    for (int i = column; i < column + length; i++) // 세로줄
    {
        if (check == -1)
            // check 가 -1이면 재귀함수로 들어가야 하므로 반복문 탈출
            break;

        for (int j = row; j < row + length; j++) // 가로줄
        {
            if (color == colorPaper[i][j])
            {
                // 첫 칸과 같은 색이면 check를 1 증가
                check++;
            }
            else
            {
                // 다른 색이면 반복문 탈출을 위해 check를 음수로 변경
                check = -1;
                break;
            }
        }
    }

    if (check == length * length)
    {
        // 모든 칸이 같은 색이면 해당 색 답 1 증가
        answer[colorPaper[column][row]]++;
        return;
    }

    recur(column, row, length / 2); // 좌측 상단 재진입
    recur(column, row + length / 2, length / 2); // 우측 상단 재진입
    recur(column + length / 2, row, length / 2); // 좌측 하단 재진입
    recur(column + length / 2, row + length / 2, length / 2); // 우측 하단 재진입
}

int main() {

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> colorPaper[i][j];
        }
    }

    recur(1, 1, n);

    cout << answer[0] << '\n' << answer[1];

    return 0;
}