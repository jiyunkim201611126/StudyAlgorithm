#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    
    int INF = drops.size() + 1;
    
    // 비가 떨어지는 최초 시점을 기록합니다.
    vector<vector<int>> rain(m, vector<int>(n, INF));
    for (int i = 0; i < drops.size(); ++i)
    {
        int r = drops[i][0];
        int c = drops[i][1];
        
        rain[r][c] = min(rain[r][c], i + 1);
    }
    
    // 왼쪽 위 지점이 될 수 있는 최대 카운트를 계산합니다.
    int rowCount = m - h + 1;
    int colCount = n - w + 1;
    
    // colMin[r][c]는 c열의 r행부터 h칸 아래까지의 최소 비 시간을 나타냅니다.
    vector<vector<int>> colMin(rowCount, vector<int>(n));
    
    for (int c = 0; c < n; ++c)
    {
        // 현재 세로 h칸 구간에서 최소값 row 후보만 남는 덱입니다.(큰 값이면서 앞에 있으면 버려짐)
        deque<int> dq;
        
        for (int r = 0; r < m; ++r)
        {
            // 현재 행의 값보다 크거나 같은 뒤쪽 행들은 앞으로 최소값이 될 수 없으므로 제거합니다.
            while (!dq.empty() && rain[dq.back()][c] >= rain[r][c])
            {
                dq.pop_back();
            }
            
            dq.push_back(r);
            
            // h칸만큼의 범위를 유지하기 위해 범위를 벗어난 앞부분 행은 제거합니다.
            if (!dq.empty() && dq.front() <= r - h)
            {
                dq.pop_front();
            }
            
            // h칸이 채워졌을 때부터 결과를 기록합니다.
            if (r >= h - 1)
            {
                int topRow = r - h + 1;
                colMin[topRow][c] = rain[dq.front()][c];
            }
        }
    }
    
    vector<int> answer;
    int bestTime = -1;
    
    // 각 topRow마다 가로 w칸 최소값을 계산합니다.
    for (int r = 0; r < rowCount; ++r)
    {
        // 현재 가로 w칸 구간에서 최소값 col 후보만 남는 덱입니다.(큰 값이면서 앞에 있으면 버려짐)
        deque<int> dq;
        
        for (int c = 0; c < n; ++c)
        {
            // 현재 열의 값보다 크거나 같은 뒤쪽 열들은 앞으로 최소값이 될 수 없으므로 제거합니다.
            while (!dq.empty() && colMin[r][dq.back()] >= colMin[r][c])
            {
                dq.pop_back();
            }
            
            dq.push_back(c);
            
            // w칸만큼의 범위를 유지하기 위해 범위를 벗어난 앞부분 열은 제거합니다.
            if (!dq.empty() && dq.front() <= c - w)
            {
                dq.pop_front();
            }
            
            // w칸이채워졌을 때부터 결과를 기록합니다.
            if (c >= w - 1)
            {
                // 현재 조회 중인 사각형의 왼쪽 지점입니다.
                int leftCol = c - w + 1;
                
                // dq에는 최소값 후보 열만 남아있고, front 열이 현재 보고 있는 사각형 중 최소값입니다.
                int currentTime = colMin[r][dq.front()];
                
                // 최소값 중 가장 큰 값을 기록합니다. 
                // 즉, '각 사각형의 가장 먼저 비 맞는 시점' 중에 '가장 늦은 시점'을 기록합니다.
                if (currentTime > bestTime)
                {
                    bestTime = currentTime;
                    answer = {r, leftCol};
                }
            }
        }
    }
    
    return answer;
}