#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Enemy1.h"

class GameScene : public cocos2d::Scene
{
public:
    GameScene();
    ~GameScene();

    virtual bool init();
    void update(float dt);
    void cameraFollowPlayer(float dt);
    cocos2d::Sprite* _player;
  
    cocos2d::Node* _camera;

    CREATE_FUNC(GameScene);

private:
    void spawnEnemy(float dt);

    cocos2d::Vector<Enemy1*> _enemies;
};

#endif // __GAME_SCENE_H__
