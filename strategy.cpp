#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>

class Boss
{
public:
    virtual ~Boss() {}
    static int HP;
};

class Player
{
public:
    virtual ~Player(){};
    static int HP;
};

class Attack
{
public:
    virtual ~Attack() {}
    virtual std::string attack_algorithm() const = 0;
};

class Battle
{
private:
    Attack *attack_;

public:
    Battle(Attack *attack = nullptr) : attack_(attack) {}
    ~Battle()
    {
        delete this->attack_;
    }

    void set_attack(Attack *attack)
    {
        delete this->attack_;
        this->attack_ = attack;
    }

    void attack() const
    {
        std::cout << "Character casting: ";
        std::string result = this->attack_->attack_algorithm();
        std::cout << result << "\n";
    }
};

class FireBolt : public Attack
{
public:
    std::string attack_algorithm() const override
    {
        std::cout << "Firebolt" << std::endl;
        int damage = rand() % 4 + 6;
        std::string result = "Zadane obrażenia przeciwnikowi: " + std::to_string(damage);
        Boss::HP = Boss::HP - damage;
        return result;
    }
};

class Slow : public Attack
{
    std::string attack_algorithm() const override
    {
        std::cout << "Slow" << std::endl;
        std::string result = "Spowolnienie akcji";
        return result;
    }
};

class IceAttack : public Attack
{
    std::string attack_algorithm() const override
    {
        std::cout << "IceAttack" << std::endl;
        int damage = rand() % 3 + 2;
        std::string result = "Zadane obrażenia przeciwnikowi: " + std::to_string(damage);
        Boss::HP = Boss::HP - damage;
        return result;
    }
};

class Disintegrate : public Attack
{
    std::string attack_algorithm() const override
    {
        std::cout << "Disintegrate" << std::endl;
        int damage = rand() % 5 + 15;
        std::string result = "Zadane obrażenia przeciwnikowi: " + std::to_string(damage);
        Boss::HP = Boss::HP - damage;
        return result;
    }
};

class Sunburst : public Attack
{
    std::string attack_algorithm() const override
    {
        std::cout << "Sunburst" << std::endl;
        int damage = rand() % 10 + 20;
        std::string result = "Zadane obrażenia przeciwnikowi: " + std::to_string(damage);
        Boss::HP = Boss::HP - damage;
        return result;
    }
};

class BosssAtack : public Attack
{
    std::string attack_algorithm() const override
    {
        std::cout << "Boss Attack" << std::endl;
        int damage = rand() % 10 + 10;
        std::string result = "Zadane obrażenia: " + std::to_string(damage);
        Player::HP = Player::HP - damage;
        return result;
    }
};

void BossAction()
{
    std::cout << "Actual Player HP: " << Player::HP << std::endl;
    Battle *battle = new Battle;
    battle->set_attack(new BosssAtack);
    battle->attack();
    std::cout << "\n";
    delete battle;
}

void PlayerAction()
{
    std::cout << "Actual Boss HP: " << Boss::HP << std::endl;
    std::cout << "Player choosed action\n";
    Battle *battle = new Battle;
    std::cout << "Choose your action:\n"
              << "1 - Firebolt\n"
              << "2 - Slow\n"
              << "3 - IceAttack\n"
              << "4 - Disintegrate\n"
              << "5 - Sunburst\n";
    int choice;
    std::cout << "your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "Player choosed action\n";
        battle->set_attack(new FireBolt);
        battle->attack();
        std::cout << "\n";
        break;

    case 2:
        std::cout << "Player choosed action\n";
        battle->set_attack(new Slow);
        battle->attack();
        std::cout << "\n";
        break;

    case 3:
        std::cout << "Player choosed action\n";
        battle->set_attack(new IceAttack);
        battle->attack();
        std::cout << "\n";
        break;

    case 4:
        std::cout << "Player choosed action\n";
        battle->set_attack(new Disintegrate);
        battle->attack();
        std::cout << "\n";
        break;

    case 5:
        std::cout << "Player choosed action\n";
        battle->set_attack(new Sunburst);
        battle->attack();
        std::cout << "\n";
        break;
    }
    delete battle;
}
int Boss::HP = 60;
int Player::HP = 40;

int main()
{
    srand(time(NULL));
    while (Boss::HP > 0 && Player::HP > 0)
    {
        PlayerAction();
        BossAction();
    }
    if (Boss::HP < 0)
    {
        std::cout << "Boss is dead, you win" << std::endl;
    }
    if (Player::HP < 0)
    {
        std::cout << "You died" << std::endl;
    }
    return 0;
}