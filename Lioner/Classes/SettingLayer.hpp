//
//  SettingLayer.hpp
//  Lioner
//
//  Created by 张伟 on 16/3/23.
//
//

#ifndef SettingLayer_hpp
#define SettingLayer_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
class SettingLayer : public Layer
{
public:
    
    static cocos2d::Scene* createScene();
    virtual bool init();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
    virtual void onExit();
    virtual void onExitTransitionDidStart();
    virtual void cleanup();
    
    void menuSoundToggleCallback(cocos2d::Ref* pSender);
    void menuMusicToggleCallback(cocos2d::Ref* pSender);
    void menuOkCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(SettingLayer);
};


#endif /* SettingLayer_hpp */




































