#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int parkSizeW = park.size();
    int parkSizeH = park[0].size();
    int currentW = 0;
    int currentH = 0;
    
    // 시작 위치를 탐색합니다.
    for (int i = 0; i < parkSizeW; ++i)
    {
        for (int j = 0; j < parkSizeH; ++j)
        {
            if (park[i][j] == 'S')
            {
                currentW = i;
                currentH = j;
                break;
            }
        }
    }
    
    for (const string& route : routes)
    {
        char direction = route[0];
        int num = route[2] - '0';
        
        if (direction == 'N')
        {
            if (currentW - num < 0)
            {
                continue;
            }
            
            bool canPass = true;
            for (int i = 1; i <= num; ++i)
            {
                if (park[currentW - i][currentH] == 'X')
                {
                    canPass = false;
                    break;
                }
            }
            
            if (canPass)
            {
                currentW -= num;
            }
        }
        else if (direction == 'S')
        {
            if (currentW + num >= parkSizeW)
            {
                continue;
            }
            
            bool canPass = true;
            for (int i = 1; i <= num; ++i)
            {
                if (park[currentW + i][currentH] == 'X')
                {
                    canPass = false;
                    break;
                }
            }
            
            if (canPass)
            {
                currentW += num;
            }
        }
        else if (direction == 'W')
        {
            if (currentH - num < 0)
            {
                continue;
            }
            
            bool canPass = true;
            for (int i = 1; i <= num; ++i)
            {
                if (park[currentW][currentH - i] == 'X')
                {
                    canPass = false;
                    break;
                }
            }
            
            if (canPass)
            {
                currentH -= num;
            }
        }
        else if (direction == 'E')
        {
            if (currentH + num >= parkSizeH)
            {
                continue;
            }
            
            bool canPass = true;
            for (int i = 1; i <= num; ++i)
            {
                if (park[currentW][currentH + i] == 'X')
                {
                    canPass = false;
                    break;
                }
            }
            
            if (canPass)
            {
                currentH += num;
            }
        }
    }
    
    answer.push_back(currentW);
    answer.push_back(currentH);
    return answer;
}