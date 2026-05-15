#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// 날짜를 정수형 값으로 변환하는 함수입니다.
int GetTotalDays(const string& date)
{
    int dateYears = stoi(date.substr(0, 4)) * 12 * 28;
    int dateMonth = stoi(date.substr(5, 7)) * 28;
    int dateDay = stoi(date.substr(8, 10));
    return dateYears + dateMonth + dateDay;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 약관 유효 기간을 정리합니다.
    unordered_map<char, int> termLength;
    for (const string& term : terms)
    {
        char termName = term[0];
        int length = stoi(term.substr(2)) * 28;
        termLength.emplace(termName, length);
    }
    
    int todayTotal = GetTotalDays(today);
    
    int privacyIndex = 1;
    for (const string& privacy : privacies)
    {
        // 약관 동의일에 유효 기간을 더해서 만료 날짜를 계산합니다.
        int privacyStartDays = GetTotalDays(privacy.substr(0, 10));
        int privacyTermLength = termLength[privacy[11]];
        int privacyEndDays = privacyStartDays + privacyTermLength - 1;
        
        // 기간이 지났다면 해당 인덱스를 기록합니다.
        if (privacyEndDays < todayTotal)
        {
            answer.push_back(privacyIndex);
        }
        ++privacyIndex;
    }
    
    return answer;
}