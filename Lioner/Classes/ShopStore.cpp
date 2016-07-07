//
//  ShopStore.cpp
//  Lioner
//
//  Created by 张伟 on 16/3/18.
//
//

#include "ShopStore.hpp"
#include "Welcome.hpp"
Scene* ShopStore:: createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = ShopStore ::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool ShopStore:: init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visibleSize=Director::getInstance()->getVisibleSize();
    
    auto background2=Sprite::create("ui/background2.png");
    background2->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    addChild(background2);
    
    auto back = MenuItemImage::create("backl.png", "backd.png", CC_CALLBACK_1(ShopStore::backmenuItemCallback, this));
    back->setPosition(Vec2(back->getContentSize().width/2, visibleSize.height-back->getContentSize().height/2));
    
    
    
    Menu *buttonmenu = Menu::create(back,NULL);
    buttonmenu->setPosition(Point::ZERO);
    addChild(buttonmenu,3);
    
    
    this->lambda=new Lambda();
    lambda->setPosition(visibleSize.width/2,visibleSize.height/2);
    addChild(lambda,2);
    lambda->action1();
    
    
    
    
    return true;
}

void ShopStore::backmenuItemCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.1, Welcome::createScene()));
}
