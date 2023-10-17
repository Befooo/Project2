#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "cocos2d.h"
#include "Enemy1.h"

class GameManager : public cocos2d::Node
{
public:
    GameManager();
    ~GameManager();

    virtual bool init();
    void update(float dt);
    Player* GameManager::getPlayer();

    CREATE_FUNC(GameManager);

private:
    void spawnEnemy(float dt);
    static Player* _player;
    cocos2d::Vector<Enemy1*> _enemies;
};

#endif // __GAME_MANAGER_H__
