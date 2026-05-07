#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    // 이름과 현재 등수를 매핑합니다.
    unordered_map<string, int> playerToRank;
    unordered_map<int, string> rankToPlayer;
    int rank = 0;
    for (const string& player : players)
    {
        playerToRank.emplace(player, rank);
        rankToPlayer.emplace(rank, player);
        ++rank;
    }
    
    // 호명을 통해 바뀐 등수를 갱신합니다.
    for (const string& overTookPlayer : callings)
    {
        int overTookPlayerRank = playerToRank[overTookPlayer];
        string overTakenPlayer = rankToPlayer[overTookPlayerRank - 1];
        int overTakenPlayerRank = overTookPlayerRank - 1;
        
        playerToRank.erase(overTookPlayer);
        playerToRank.erase(overTakenPlayer);
        rankToPlayer.erase(overTookPlayerRank);
        rankToPlayer.erase(overTakenPlayerRank);
        
        playerToRank.emplace(overTookPlayer, overTakenPlayerRank);
        playerToRank.emplace(overTakenPlayer, overTookPlayerRank);
        rankToPlayer.emplace(overTookPlayerRank, overTakenPlayer);
        rankToPlayer.emplace(overTakenPlayerRank, overTookPlayer);
    }
    
    for (int i = 0; i < players.size(); ++i)
    {
        answer.push_back(rankToPlayer[i]);
    }
    
    return answer;
}