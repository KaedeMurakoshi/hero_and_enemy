#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <cstring>
#include"hero_and_enemy.h"
using namespace std;

// メンバ変数は基本プライベート、変数名の先頭に　＿　をつける。

const int MAX_NAME = 32;
const int HEAL_AMOUNT = 30;

// コンストラクタ
Hero::Hero(char* pName, int hp)
{
    _nameSize = strlen(pName);  // 半角前提

    // 動的確保
    _pName = new char[_nameSize + 1];
    strcpy(_pName, pName);

    // パラメータ初期化
    _hp = hp;
    _atk = 75;
    _def = 20;
}

// デストラクタ
Hero::~Hero()
{
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void Hero::Show()
{
    printf("名前 : %s\n", _pName);
    printf("体力 : %d\n", _hp);
    printf("攻撃力 : %d\n", _atk);
    printf("防御力 : %d\n", _def);
}

// コンストラクタ
Enemy::Enemy(char* pName, int hp)
{
    _nameSize = strlen(pName);  // 半角前提
    
    // 動的確保
    _pName = new char[_nameSize + 1];
    strcpy(_pName, pName);

    // パラメータ初期化
    _hp = hp;
    _atk = 75;
    _def = 20;
}

// デストラクタ
Enemy::~Enemy()
{
    if (_pName != NULL)
    {
        delete[] _pName;
        _pName = NULL;
    }
}

void Enemy::Show()
{
    printf("名前 : %s\n", _pName);
    printf("体力 : %d\n", _hp);
    printf("攻撃力 : %d\n", _atk);
    printf("防御力 : %d\n", _def);
}

Hero InputHeroStatus()
{
    char name[MAX_NAME]{""};
    int hp = 0;

    printf("自分の名前を入力 > ");
    cin >> name;
    printf("\n自分のHPを入力 >");
    cin >> hp;

    Hero hero(&name[0], hp);

    // 表示
    hero.Show();

    // 実体を返す
    return hero;
}

Enemy InputEnemyStatus()
{
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("敵の名前を入力 > ");
    cin >> name;
    printf("\n敵のHPを入力 >");
    cin >> hp;

    Enemy enemy(&name[0], hp);

    // 表示
    enemy.Show();

    // 実体を返す
    return enemy;
}

void Hero::Attack(Enemy* enemy)
{
    int def = enemy->GetDef();
    int damage = _atk - def;
    printf("%sの攻撃！\n%dのダメージ\n", _pName, damage);

    int hp = enemy->GetHp();
    enemy->SetHp(hp - damage);
    printf("相手の残りHP : &d\n");
}

void Enemy::Attack(Hero* hero)
{
    int def = hero->GetDef();
    int damage = _atk - def;
    printf("%sの攻撃！\n%dのダメージ\n", _pName, damage);

    int hp = hero->GetHp();
    hero->SetHp(hp - damage);
    printf("相手の残りHP : &d\n");
}

void Hero::Heal()
{
    _hp += HEAL_AMOUNT;

    printf("%sの残りHP : %d\n", _pName, _hp);
}

void Enemy::Heal()
{
    _hp += HEAL_AMOUNT;

    printf("%sの残りHP : %d\n", _pName, _hp);
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
