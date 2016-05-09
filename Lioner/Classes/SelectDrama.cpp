//
//  SelectDrama.cpp
//  Lioner
//
//  Created by 张伟 on 16/3/28.
//
//

#include "SelectDrama.hpp"
Scene* SelectDrama::createscene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SelectDrama::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;

    
}

bool SelectDrama::init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg=Sprite::create("ui/background2.png");
    bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(bg);
    
    
    

    return true;
}

void SelectDrama::setstring(int sc)
{
    log("------%d------",sc);
}

