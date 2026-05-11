#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int lux = 999999;
    int luy = 999999;
    int rdx = -1;
    int rdy = -1;
    
    for (int i = 0; i < wallpaper.size(); ++i)
    {
        for (int j = 0; j < wallpaper[i].size(); ++j)
        {
            if (wallpaper[i][j] == '#')
            {
                if (i < lux)
                {
                    lux = i;
                }
                if (j < luy)
                {
                    luy = j;
                }
                if (i + 1 > rdx)
                {
                    rdx = i + 1;
                }
                if (j + 1 > rdy)
                {
                    rdy = j + 1;
                }
            }
        }
    }
    
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx);
    answer.push_back(rdy);
    
    return answer;
}