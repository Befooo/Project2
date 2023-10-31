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
    _player = Player::create();
    _player->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));
    this->addChild(_player);
    _camera = cocos2d::Node::create();
    this->addChild(_camera);
    this->scheduleUpdate();
    return true;
}


void GameScene::update(float dt)
{
    for (auto enemy : _enemies)
    {
        //enemy->move();
    }
    cameraFollowPlayer(dt);
}


void GameScene::cameraFollowPlayer(float dt)
{
    if (_player)
    {
        Vec2 playerPos = _player->getPosition();
        Size screenSize = Director::getInstance()->getVisibleSize();

        float x = MAX(playerPos.x, screenSize.width / 2);
        float y = MAX(playerPos.y, screenSize.height / 2);
        Vec2 targetPos = Vec2(-x + screenSize.width / 2, -y + screenSize.height / 2);

        const float lerp = 0.1f;
        Vec2 newPos = this->getPosition() * (1 - lerp) + targetPos * lerp;

        this->setPosition(newPos);

    }
}



void GameScene::spawnEnemy(float dt)
{
    auto enemy = Enemy1::create();
    _enemies.pushBack(enemy);
    this->addChild(enemy);
}
//void GameScene::cameraFollowPlayer() {
//    GameManager* gameManager = GameManager::getPlayer();
//
//    if (gameManager != nullptr)
//    {
//        auto sprite = gameManager->getSprite();
//        if (sprite != nullptr)
//        {
//            Vec2 playerPos = sprite->getPosition();
//            auto visibleSize = Director::getInstance()->getVisibleSize();
//            auto camera = getDefaultCamera();
//            camera->setPosition(playerPos);
//        }
//    }
//}