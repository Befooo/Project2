#include "GameScene.h"
#include "GameManager.h"
#include "Player.h"

USING_NS_CC;

GameScene::GameScene() {}

GameScene::~GameScene() {}

bool GameScene::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto gameManager = GameManager::create();
    this->addChild(gameManager);
    auto player = Player::create();
    player->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
    this->addChild(player);
    return true;
}


void GameScene::update(float dt)
{
    for (auto enemy : _enemies)
    {
        //enemy->move();
    }

}

void GameScene::spawnEnemy(float dt)
{
    auto enemy = Enemy1::create();
    _enemies.pushBack(enemy);
    this->addChild(enemy);
}
