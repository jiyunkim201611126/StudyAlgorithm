#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    int digits = p.size();
    long long pNumber = stoll(p);
    
    for (int i = 0; i <= t.size() - digits; ++i)
    {
        long long currentNumber = stoll(t.substr(i, digits));
        
        if (currentNumber <= pNumber)
        {
            ++answer;
        }
    }
    
    return answer;
}