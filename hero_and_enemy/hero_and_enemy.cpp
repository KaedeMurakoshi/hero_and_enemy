// hero_and_enemy.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

const int HEAL_AMOUNT;

class Hero {
public:
    char* name;
    int hp;
    int atk;
    int def;

    Hero();
    void Attack(Enemy* enemy);
    void Heal();
    void Getter();
    void Setter();
};

class Enemy {
public:
    const char* name;
    int hp;
    int atk;
    int def;

    Enemy();

    void Attack(Hero* hero);
    void Heal();
};

void Hero::Attack(Enemy* enemy)
{
    int damage = atk - enemy->def;
    if (damage < 0) { damage = 0;}
    enemy->hp -= damage;
}

void Hero::Heal()
{
    hp += HEAL_AMOUNT;
}

void Enemy::Attack(Hero* hero)
{
    int damage = atk - hero->def;
    if (damage < 0) { damage = 0;}
    hero->hp -= damage;
}

void Enemy::Heal()
{
    hp += HEAL_AMOUNT;
}

Hero::Hero()
{
    name = new char[32];
    hp = 100;
    atk = 50;
    def = 30;
}

Enemy::Enemy() 
{
    name = "エルギオス";
    hp = 100;
    atk = 50;
    def = 30;
}

void Hero::Getter()
{

}

void Hero::Setter()
{

}

int main()
{

}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
