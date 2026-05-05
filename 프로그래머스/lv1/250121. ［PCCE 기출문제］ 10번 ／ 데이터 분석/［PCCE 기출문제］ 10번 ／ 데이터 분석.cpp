#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int stringToIndex(const string& inString)
{
    if (inString == "code")
    {
        return 0;
    }
    else if (inString == "date")
    {
        return 1;
    }
    else if (inString == "maximum")
    {
        return 2;
    }
    else
    {
        return 3;
    }
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    // ext에 해당하는 Index를 가져옵니다.
    int extIndex = stringToIndex(ext);
    
    // ext와 val_ext를 기준으로 필터링합니다.
    for (int i = 0; i < data.size(); ++i)
    {
        if (data[i][extIndex] < val_ext)
        {
            answer.push_back(data[i]);
        }
    }
    
    int sortbyIndex = stringToIndex(sort_by);
    sort(answer.begin(), answer.end(),
        [sortbyIndex](const vector<int>& a, const vector<int>& b)
         {
             return a[sortbyIndex] < b[sortbyIndex];
         });
    
    return answer;
}