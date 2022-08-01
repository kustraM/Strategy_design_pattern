/**
 * @todo zadawane obrażenia od ataków
 * @todo wybór przez gracza używanego ataku
 *
 */
#include <iostream>
#include <string>
#include <time.h>
#include <algorithm>

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
        return result;
    }
};

void PlayerAction()
{
    std::cout << "Player choosed action\n";
    Battle *battle = new Battle(new FireBolt);
    battle->attack();
    std::cout << "\n";

    std::cout << "Player choosed action\n";
    battle->set_attack(new Slow);
    battle->attack();
    std::cout << "\n";

    std::cout << "Player choosed action\n";
    battle->set_attack(new IceAttack);
    battle->attack();
    std::cout << "\n";

    std::cout << "Player choosed action\n";
    battle->set_attack(new Disintegrate);
    battle->attack();
    std::cout << "\n";

    std::cout << "Player choosed action\n";
    battle->set_attack(new Sunburst);
    battle->attack();
    delete battle;
}

int main()
{
    srand(time(NULL));
    PlayerAction();
    return 0;
}