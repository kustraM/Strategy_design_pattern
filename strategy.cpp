#include <iostream>
#include <string>
#include <vector>
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

    void set_strategy(Attack *attack)
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
        std::string result = "Fire bolt";
        return result;
    }
};

class Slow : public Attack
{
    std::string attack_algorithm() const override
    {
        std::string result = "Slow";
        return result;
    }
};

class IceAttack : public Attack
{
    std::string attack_algorithm() const override
    {
        std::string result = "IceAttack";
        return result;
    }
};

class Disintegrate : public Attack
{
    std::string attack_algorithm() const override
    {
        std::string result = "Disintegrate";
        return result;
    }
};

class Sunburst : public Attack
{
    std::string attack_algorithm() const override
    {
        std::string result = "Sunburst";
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
    battle->set_strategy(new Slow);
    battle->attack();
    std::cout << "\n";

    std::cout << "Player choosed action\n";
    battle->set_strategy(new IceAttack);
    battle->attack();
    std::cout << "\n";

    std::cout << "Player choosed action\n";
    battle->set_strategy(new Disintegrate);
    battle->attack();
    std::cout << "\n";

    std::cout << "Player choosed action\n";
    battle->set_strategy(new Sunburst);
    battle->attack();
    delete battle;
}

int main()
{
    PlayerAction();
    return 0;
}