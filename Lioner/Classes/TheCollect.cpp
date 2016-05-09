//
//  TheCollect.cpp
//  Lioner
//
//  Created by 张伟 on 16/3/20.
//
//

#include "TheCollect.hpp"
#include "Welcome.hpp"
Scene* TheCollect :: createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TheCollect ::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool TheCollect:: init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visiblesize=Director::getInstance()->getVisibleSize();
    
    auto background2=Sprite::create("ui/background2.png");
    background2->setPosition(Vec2(visiblesize.width/2, visiblesize.height/2));
    addChild(background2);
    
    auto back = MenuItemImage::create("backl.png", "backd.png", CC_CALLBACK_1(TheCollect::backmenuItemCallback, this));
    back->setPosition(Vec2(back->getContentSize().width/2, visiblesize.height-back->getContentSize().height/2));
    
    Menu *buttonmenu = Menu::create(back,NULL);
    buttonmenu->setPosition(Point::ZERO);
    addChild(buttonmenu,3);
    
    return true;
}

void TheCollect::backmenuItemCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.1, Welcome::createScene()));
}

