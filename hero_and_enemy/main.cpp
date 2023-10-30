#include <iostream>
#include"hero_and_enemy.h"
using namespace std;

// プロトタイプ宣言
void ShowStatus(Hero hero, Enemy enemy);
Hero InputHeroStatus();
Enemy InputEnemyStatus();

int main()
{
    // クラスの実体を宣言
    Hero hero = InputHeroStatus();
    Enemy enemy = InputEnemyStatus();

    ShowStatus(hero, enemy);
}