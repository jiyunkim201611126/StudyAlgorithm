#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    int answer = 0;
    
    // 일반 단어들을 모아두는 set입니다.
    unordered_set<string> normalWords;
    
    // x번째 스포일러를 공개하면 나타나는 단어를 모아두는 2차원 배열입니다.
    vector<vector<string>> buckets(spoiler_ranges.size());
    
    int n = message.size();
    int i = 0;
    int rangeIndex = 0;
    
    // 문장에서 단어의 위치들을 구합니다.
    while (i < n)
    {
        // 공백은 스킵합니다.
        if (message[i] == ' ')
        {
            ++i;
            continue;
        }
        
        // 단어 끝까지 이동해서 인덱스를 기록합니다.
        int wordStart = i;
        while (i < n && message[i] != ' ')
        {
            ++i;
        }
        int wordEnd = i - 1;
        
        string word = message.substr(wordStart, wordEnd - wordStart + 1);
        
        // 현재 단어보다 왼쪽에 있는 스포일러 구간은 제거합니다.
        while (rangeIndex < spoiler_ranges.size() && spoiler_ranges[rangeIndex][1] < wordStart)
        {
            ++rangeIndex;
        }
        
        int revealIndex = -1;
        int k = rangeIndex;
        
        // 현재 단어를 스포일러로 덮을 수 있는 구간을 검사합니다.
        while (k < spoiler_ranges.size() && spoiler_ranges[k][0] <= wordEnd)
        {
            int rangeStart = spoiler_ranges[k][0];
            int rangeEnd = spoiler_ranges[k][1];
            
            if (rangeStart <= wordEnd || wordStart <= rangeEnd)
            {
                revealIndex = k;
            }
            ++k;
        }
        
        if (revealIndex == -1)
        {
            normalWords.insert(word);
        }
        else
        {
            buckets[revealIndex].push_back(word);
        }
    }
    
    // 처음 공개된 스포일러 단어를 모아두는 set입니다.
    unordered_set<string> revealedSpoilerWords;
    
    for (int r = 0; r < buckets.size(); ++r)
    {
        for (const string& word : buckets[r])
        {
            // 이전에 일반 단어로 공개된 적이 없으면서, 처음으로 공개된 스포일러 단어라면 카운트합니다.
            if (!normalWords.count(word) && !revealedSpoilerWords.count(word))
            {
                ++answer;
            }
            
            // 스포일러로 공개된 단어여도 중복이라면 카운트하지 않기 위해 추가합니다.
            revealedSpoilerWords.insert(word);
        }
    }
    
    return answer;
}