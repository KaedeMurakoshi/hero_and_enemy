#pragma once

class Enemy;    // �O���錾�i�v���g�^�C�v�錾�Ɠ����j

class Hero {
private:
    char* _pName;
    int _nameSize;
    int _hp;
    int _atk;
    int _def;

public:
    void operator=(const Hero& other);   // ������Z�q�̃I�[�o�[���[�h

public:
    Hero(const Hero& other);    // �R�s�[�R���X�g���N�^
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
    void operator=(const Enemy& other);   // ������Z�q�̃I�[�o�[���[�h

public:
    Enemy(const Enemy& other);  // �R�s�[�R���X�g���N�^
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