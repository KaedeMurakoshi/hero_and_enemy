#include <iostream>
#include"hero_and_enemy.h"
using namespace std;

// �v���g�^�C�v�錾
void ShowStatus(Hero hero, Enemy enemy);
Hero InputHeroStatus();
Enemy InputEnemyStatus();

int main()
{
    // �N���X�̎��̂�錾
    Hero hero = InputHeroStatus();
    Enemy enemy = InputEnemyStatus();

    ShowStatus(hero, enemy);
}