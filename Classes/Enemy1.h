#ifndef __ENEMY1_H__
#define __ENEMY1_H__

#include "cocos2d.h"
#include "Player.h"

class Enemy1 : public cocos2d::Sprite
{
public:
    Enemy1();
    ~Enemy1();

    virtual bool init();
    CREATE_FUNC(Enemy1);

    void setPlayer(Player* player);
    void update(float dt);

private:
    Player* _player;
};

#endif // __ENEMY1_H__
