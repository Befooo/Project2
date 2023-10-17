#include "Player.h"

USING_NS_CC;

Player::Player() {}

Player::~Player() {}


bool Player::init()
{
    if (!Sprite::initWithFile("player.png"))
    {
        return false;
    }

    this->setAnchorPoint(Vec2(0.5f, 0.5f));
    this->setScale(0.3f);

    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
    listener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);

    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    this->schedule(CC_SCHEDULE_SELECTOR(Player::update));

    return true;
}


void Player::update(float dt)
{
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_A))
    {
        // Move player to the left
        this->setPositionX(this->getPositionX() - 10);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_D))
    {
        // Move player to the right
        this->setPositionX(this->getPositionX() + 10);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_W))
    {
        // Move player up
        this->setPositionY(this->getPositionY() + 10);
    }
    if (isKeyPressed(EventKeyboard::KeyCode::KEY_S))
    {
        // Move player down
        this->setPositionY(this->getPositionY() - 10);
    }
}

bool Player::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
    if (keys.find(keyCode) != keys.end())
        return true;
    return false;
}

void Player::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    if (keys.find(keyCode) == keys.end())
        keys[keyCode] = std::chrono::high_resolution_clock::now();
}

void Player::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    keys.erase(keyCode);
}
