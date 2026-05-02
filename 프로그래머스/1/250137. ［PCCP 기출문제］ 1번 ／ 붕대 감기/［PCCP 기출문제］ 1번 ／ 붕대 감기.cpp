#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int healValue = bandage[1];
    int healBonusTime = bandage[0];
    int healBonusValue = bandage[2];
    
    int maxHealth = health;
    
    int previousAttackTime = 0;
    for (auto& attack : attacks)
    {
        int attackTime = attack[0];
        int damage = attack[1];
        
        // 직전 공격부터 시간이 얼마나 경과했는지를 통해 붕대 감기가 몇 번 적용됐는지 계산합니다.
        int bandageTick = attackTime - previousAttackTime - 1;
        
        // 직전 공격 시간을 갱신합니다.
        previousAttackTime = attackTime;
        
        // 힐 총량을 계산합니다.
        int resultHeal = (bandageTick * healValue) + ((bandageTick / healBonusTime) * healBonusValue);
        
        // 힐 총량에 따른 현재 체력을 계산합니다.
        health = min(health + resultHeal, maxHealth);
        
        // 데미지를 계산합니다.
        health -= damage;
        
        // 사망한 경우 -1을 반환합니다.
        if (health <= 0)
        {
            return -1;
        }
    }
    
    answer = health;
    return answer;
}