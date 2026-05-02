#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int walletLong = wallet[0] < wallet[1] ? wallet[1] : wallet[0];
    int walletShort = wallet[0] < wallet[1] ? wallet[0] : wallet[1];
    
    cout << walletLong << " " << walletShort << '\n';
    
    while (true)
    {
        int billLong = bill[0] < bill[1] ? bill[1] : bill[0];
        int billShort = bill[0] < bill[1] ? bill[0] : bill[1];
        
        if (billLong <= walletLong && billShort <= walletShort)
        {
            break;
        }
        
        if (bill[0] < bill[1])
        {
            bill[1] /= 2;
        }
        else
        {
            bill[0] /= 2;
        }
        
        cout << bill[0] << " " << bill[1] << '\n';
        
        answer++;
    }
    
    return answer;
}