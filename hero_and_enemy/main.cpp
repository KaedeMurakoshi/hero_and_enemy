#include <iostream>
#include"hero_and_enemy.h"
using namespace std;

Hero InputHeroStatus();
Enemy InputEnemyStatus();

int main()
{
    // クラスの実体を宣言
    Hero hero = InputHeroStatus();
    Enemy enemy = InputEnemyStatus();

    bool turn = false;
}