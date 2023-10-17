#include "GameManager.h"

USING_NS_CC;

GameManager::GameManager() {}

GameManager::~GameManager() {}

Player* GameManager::_player = nullptr;

bool GameManager::init()
{
    if (!Node::init())
    {
        return false;
    }

    schedule(CC_SCHEDULE_SELECTOR(GameManager::spawnEnemy), 1.0f);

    scheduleUpdate();

    return true;
}

void GameManager::update(float dt)
{
    for (auto enemy : _enemies)
    {
        //enemy->move();
    }   
}      

Player* GameManager::getPlayer() {
    return GameManager::_player;
}

void GameManager::spawnEnemy(float dt)
{
    auto enemy = Enemy1::create();

    // Get the screen size
    auto screenSize = Director::getInstance()->getVisibleSize();

    float marginX = 100.0f;
    float marginY = 100.0f;

    float randX, randY;

    // Decide randomly if the enemy should spawn at the top/bottom or left/right
    if (RandomHelper::random_int(0, 1) == 0) {
        // Spawn at top or bottom
        randX = RandomHelper::random_real(0.0f, screenSize.width);
        randY = (RandomHelper::random_int(0, 1) == 0) ? RandomHelper::random_real(screenSize.height - marginY, screenSize.height) : RandomHelper::random_real(0.0f, marginY);
    }
    else {
        // Spawn at left or right
        randX = (RandomHelper::random_int(0, 1) == 0) ? RandomHelper::random_real(0.0f, marginX) : RandomHelper::random_real(screenSize.width - marginX, screenSize.width);
        randY = RandomHelper::random_real(0.0f, screenSize.height);
    }

    enemy->setPosition(Vec2(randX, randY));

    _enemies.pushBack(enemy);

    this->addChild(enemy);
}


