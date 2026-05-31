#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

void Forklift(vector<string>& board, char target)
{
    int height = board.size();
    int width = board[0].size();
    
    vector<vector<bool>> visited(height, vector<bool>(width, false));
    queue<pair<int, int>> q;
    vector<pair<int, int>> removeList;
    
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    q.push({0, 0});
    visited[0][0] = true;
    
    // 바깥에서부터 접근 가능한 모든 컨테이너를 찾고, target이라면 제거하도록 BFS를 돕니다.
    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();
        
        for (int direction = 0; direction < 4; ++direction)
        {
            int ny = y + dy[direction];
            int nx = x + dx[direction];
            
            if (ny < 0 || ny >= height || nx < 0 || nx >= width)
            {
                continue;
            }
            
            if (visited[ny][nx])
            {
                continue;
            }
            
            if (board[ny][nx] == '.')
            {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
            else if (board[ny][nx] == target)
            {
                visited[ny][nx] = true;
                removeList.push_back({ny, nx});
            }
        }
    }
    
    for (auto [y, x] : removeList)
    {
        board[y][x] = '.';
    }
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    
    // 상하좌우로 1칸씩 빈칸으로 넓혀놓은 board를 선언 및 초기화합니다.
    int n = storage.size();
    int m = storage[0].size();
    vector<string> board(n + 2, string(m + 2, '.'));
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            board[y + 1][x + 1] = storage[y][x];
        }
    }
    
    for (const string& request : requests)
    {
        if (request.size() == 1)
        {
            // 지게차 요청인 경우 들어오는 분기입니다.
            Forklift(board, request[0]);
        }
        else
        {
            // 크레인 요청인 경우 들어오는 분기입니다.
            for (int y = 0; y < board.size(); ++y)
            {
                for (int x = 0; x < board[0].size(); ++x)
                {
                    if (board[y][x] == request[0])
                    {
                        board[y][x] = '.';
                    }
                }
            }
        }
    }
    
    for (int y = 1; y <= n; ++y)
    {
        for (int x = 1; x <= m; ++x)
        {
            if (board[y][x] != '.')
            {
                ++answer;
            }
        }
    }
    
    return answer;
}