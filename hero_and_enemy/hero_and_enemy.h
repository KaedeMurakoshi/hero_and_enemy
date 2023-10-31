#pragma once

class Enemy;    // 前方宣言（プロトタイプ宣言と同じ）

class Hero {
private:
    char* _pName;
    int _nameSize;
    int _hp;
    int _atk;
    int _def;

public:
    void operator=(const Hero& other);   // 代入演算子のオーバーロード

public:
    Hero(const Hero& other);    // コピーコンストラクタ
    Hero(char* pName, int hp);
    ~Hero();

public:
    int GetDef() { return _def; }
    int GetHp() { return _hp; }
    int GetAtk() { return _atk; }
    void SetHp(int hp) { _hp = hp; }

public:
    void Show();
    void Attack(Enemy* enemy);
    void Heal();
};

class Enemy {
private:
    char* _pName;
    int _nameSize;
    int _hp;
    int _atk = 50;
    int _def = 20;

public:
    void operator=(const Enemy& other);   // 代入演算子のオーバーロード

public:
    Enemy(const Enemy& other);  // コピーコンストラクタ
    Enemy(char* pName, int hp);
    ~Enemy();

public: 
    int GetAtk() { return _atk; }
    int GetDef() { return _def; }
    int GetHp() { return _hp; }

    void SetHp(int hp)
    {
        _hp = hp;
    }

public:
    void Show();
    void Attack(Hero* hero);
    void Heal();
};