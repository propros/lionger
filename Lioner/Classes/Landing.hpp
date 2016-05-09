//
//  Landing.hpp
//  Lioner
//
//  Created by 张伟 on 16/3/3.
//
//

#ifndef Landing_hpp
#define Landing_hpp

#include <stdio.h>
#include "Welcome.hpp"
#include "cocos2d.h"

using namespace cocos2d;

class Landing : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    void logo();
    
    void nextScene();
public:
    
//    ProgressTimer* progresstimers;
//    float percentage;
//    bool isshown;
    Sprite* thelogo;
    Sprite* bgsprite;
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    
    CREATE_FUNC(Landing);
};


#endif /* Landing_hpp */
