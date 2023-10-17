#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"

class Player : public cocos2d::Sprite
{
public:
    Player();
    ~Player();

    virtual bool init();
    CREATE_FUNC(Player);

    void update(float dt);

    bool isKeyPressed(cocos2d::EventKeyboard::KeyCode);
    double keyPressedDuration(cocos2d::EventKeyboard::KeyCode);

private:
    cocos2d::Sprite* player;
    std::map<cocos2d::EventKeyboard::KeyCode,
        std::chrono::high_resolution_clock::time_point> keys;

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
    void onKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
};

#endif // __PLAYER_H__
