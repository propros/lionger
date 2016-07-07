//
//  Landing.cpp
//  Lioner
//
//  Created by 张伟 on 16/3/3.
//
//

#include "Landing.hpp"

Scene* Landing::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Landing::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool Landing::init()
{
    if ( !LayerColor ::initWithColor(Color4B(255, 255, 255, 255)) )
    {
        return false;
    }
    
    Size visiblesize=Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    thelogo=Sprite::create("ui/logo.png");
    thelogo->setScale(0.7);
    thelogo->setTag(101);
    thelogo->setPosition(Vec2(visiblesize.width/2, visiblesize.height/1.8));
    addChild(thelogo);
    
    auto touchme=Sprite::create("ui/touch.png");
    touchme->setScale(0.9);
    touchme->setPosition(Vec2(visiblesize.width/2, visiblesize.height/6));
    this->addChild(touchme);
    
    auto fadeout=FadeOut::create(1);
    auto fadein=FadeIn::create(1);
    auto seq=Sequence::create(fadeout,fadein, NULL);
    touchme->runAction(RepeatForever::create(seq));
    
    auto listener=EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan=CC_CALLBACK_2(Landing::onTouchBegan, this);
    
    EventDispatcher * eventDispatcher=Director::getInstance()->getEventDispatcher();
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, getChildByTag(101));

   
    return true;
    
}

bool Landing::onTouchBegan(Touch *touch, Event *unused_event)
{
    nextScene();
    return true;
}

void Landing::nextScene()
{
    auto scene=TransitionFade::create(0.1f, Welcome::createScene());
    Director::getInstance()->replaceScene(scene);
}

