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

void PlayerAction()
{
    std::cout << "Player choosed action\n";
    Battle *context = new Battle(new FireBolt);
    context->attack();
    std::cout << "\n";
    std::cout << "Player choosed action\n";
    context->set_strategy(new Slow);
    context->attack();
    delete context;
}

int main()
{
    PlayerAction();
    return 0;
}