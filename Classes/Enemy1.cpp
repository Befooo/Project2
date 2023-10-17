#include "Enemy1.h"
#include "GameManager.h"

USING_NS_CC;

Enemy1::Enemy1() : _player(nullptr) {}

Enemy1::~Enemy1() {}

bool Enemy1::init()
{
    if (!Sprite::initWithFile("HelloWorld.png"))
    {
        return false;
    }

    this->schedule(CC_SCHEDULE_SELECTOR(Enemy1::update));

    return true;
    //abc
    //1asfj
}

void Enemy1::setPlayer(Player* player)
{
    _player = player;
}

void Enemy1::update(float dt)
{
    if (_player)
    {
        // Get the direction vector from the enemy to the player
        Vec2 direction = _player->getPosition() - this->getPosition();

        // Normalize the direction vector
        direction.normalize();

        // Move the enemy towards the player
        this->setPosition(this->getPosition() + direction);
    }
}
