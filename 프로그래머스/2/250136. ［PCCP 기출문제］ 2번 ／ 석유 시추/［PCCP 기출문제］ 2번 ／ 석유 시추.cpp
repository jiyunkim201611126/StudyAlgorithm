#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> land) {
    int n = land.size();
    int m = land[0].size();
    
    // 석유가 있는 덩어리를 하나의 Room으로 라벨링하는 2차원 배열입니다.
    vector<vector<int>> landRoom(n, vector<int>(m, 0));
    // Room에 총 석유가 몇 칸 있는지 기록하는 배열입니다. 석유가 없는 칸은 0으로 라벨링할 예정이므로 0을 하나 넣어둡니다.
    vector<int> roomSize(1, 0);
    
    int roomId = 1;
    
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            if (land[y][x] == 0 || landRoom[y][x] != 0)
            {
                // 석유가 없는 칸이거나, 이미 Room으로 라벨링이 된 칸이라면 스킵합니다.
                continue;
            }
            
            // 석유가 있는 칸이라면 BFS를 시작합니다.
            queue<pair<int, int>> q;
            q.push({y, x});
            landRoom[y][x] = roomId;
            
            int size = 0;
            
            while (!q.empty())
            {
                auto [cy, cx] = q.front();
                q.pop();
                
                ++size;
                
                for (int dir = 0; dir < 4; ++dir)
                {
                    int ny = cy + dy[dir];
                    int nx = cx + dx[dir];
                    
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    {
                        // 범위를 벗어난 경우 스킵합니다.
                        continue;
                    }
                    
                    if (land[ny][nx] == 0 || landRoom[ny][nx] != 0)
                    {
                        // 석유가 없는 칸이거나, 이미 라벨링이 된 칸이라면 스킵합니다.
                        continue;
                    }
                    
                    landRoom[ny][nx] = roomId;
                    q.push({ny, nx});
                }
            }
            
            // 석유가 있는 덩어리 칸의 사이즈를 기록합니다.
            roomSize.push_back(size);
            ++roomId;
        }
    }
    
    int answer = 0;
    
    // 모든 열을 순회합니다.
    for (int col = 0; col < m; ++col)
    {
        vector<bool> visitedRoom(roomSize.size(), false);
        int sum = 0;
        
        for (int row = 0; row < n; ++row)
        {
            int currentRoomId = landRoom[row][col];
            if (currentRoomId == 0 || visitedRoom[currentRoomId])
            {
                // 석유가 없는 칸이거나 이미 방문한 Room은 스킵합니다.
                continue;
            }
            
            visitedRoom[currentRoomId] = true;
            
            // 시추기가 통과한 Room의 사이즈를 합산합니다.
            sum += roomSize[currentRoomId];
        }
        
        answer = max(answer, sum);
    }
    
    return answer;
}