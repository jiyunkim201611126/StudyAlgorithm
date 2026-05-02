#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    // 서로 선물을 얼마나 주고받았는지 기록합니다.
    vector<vector<int>> friendToFriend(friends.size(), vector<int>(friends.size(), 0));
    
    // 이름과 인덱스를 매핑합니다.
    unordered_map<string, int> nameToIndex;
    
    // 인덱스와 선물 지수를 매핑합니다.
    vector<int> giftValues(friends.size(), 0);
    
    for (int i = 0; i < friends.size(); ++i)
    {
        nameToIndex[friends[i]] = i;
    }
    
    for (string& gift : gifts)
    {
        // 선물 내역에서 공백 인덱스를 탐색합니다.
        int spaceIndex = gift.find(' ');
        
        // 공백을 기준으로 앞뒤로 구분합니다.
        string from = gift.substr(0, spaceIndex);
        string to = gift.substr(spaceIndex + 1);
        
        int fromIndex = nameToIndex[from];
        int toIndex = nameToIndex[to];
        
        ++friendToFriend[fromIndex][toIndex];
        
        ++giftValues[fromIndex];
        --giftValues[toIndex];
    }
    
    // 중복된 값이 들어가지 않도록 표 기준으로 우상단만 순회합니다.
    vector<int> willReceives(friends.size(), 0);
    for (int i = 0; i < friends.size(); ++i)
    {
        for (int j = i + 1; j < friends.size(); ++j)
        {
            int iToj = friendToFriend[i][j];
            int jToi = friendToFriend[j][i];
            
            // 주고받은 여부 및 선물 지수에 따라 누가 받을지 결정합니다.
            if (iToj < jToi)
            {
                ++willReceives[j];
            }
            else if (jToi < iToj)
            {
                ++willReceives[i];
            }
            else
            {
                if (giftValues[i] < giftValues[j])
                {
                    ++willReceives[j];
                }
                else if (giftValues[j] < giftValues[i])
                {
                    ++willReceives[i];
                }
            }
        }
    }
    
    for (int willReceive : willReceives)
    {
        if (answer < willReceive)
        {
            answer = willReceive;
        }
    }
    
    return answer;
}