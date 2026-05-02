#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iostream>

using namespace std;

int toSecond(string time)
{
    int minute = stoi(time.substr(0, 2));
    int second = stoi(time.substr(3, 2));
    
    return minute * 60 + second;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    size_t colonPos = video_len.find(':');
    
    int videoLength = toSecond(video_len);
    int currentPos = toSecond(pos);
    int openingStart = toSecond(op_start);
    int openingEnd = toSecond(op_end);
    
    for (string command : commands)
    {
        if (command == "next")
        {
            if (openingStart <= currentPos && currentPos <= openingEnd)
            {
                currentPos = openingEnd;
            }
            currentPos += 10;
            if (videoLength <= currentPos)
            {
                currentPos = videoLength;
            }
            else if (openingStart <= currentPos && currentPos <= openingEnd)
            {
                currentPos = openingEnd;
            }
        }
        else if (command == "prev")
        {
            if (openingStart <= currentPos && currentPos <= openingEnd)
            {
                currentPos = openingEnd;
            }
            currentPos -= 10;
            if (currentPos <= 0)
            {
                currentPos = 0;
            }
            else if (openingStart <= currentPos && currentPos <= openingEnd)
            {
                currentPos = openingEnd;
            }
        }
    }
    
    int resultMinute = currentPos / 60;
    int resultSecond = currentPos % 60;
    
    ostringstream oss;
    oss << setw(2) << setfill('0') << resultMinute;
    oss << ":";
    oss << setw(2) << setfill('0') << resultSecond;
    
    answer = oss.str();
    
    return answer;
}