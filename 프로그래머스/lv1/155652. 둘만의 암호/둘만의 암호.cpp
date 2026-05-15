#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    
    set<char> skipLetters;
    for (int i = 0; i < skip.size(); ++i)
    {
        skipLetters.insert(skip[i]);
    }
    
    for (int i = 0; i < s.size(); ++i)
    {
        for (int j = 0; j < index; ++j)
        {
            s[i] = (s[i] - 'a' + 1) % 26 + 'a';
            if (skipLetters.find(s[i]) != skipLetters.end())
            {
                --j;
            }
        }
    }
    
    return s;
}