

#include "Welcome.hpp"
#include "PlayLayer.h"
#include "ShopStore.hpp"
#include "TheDrama.hpp"
#include "TheCollect.hpp"
#include "SettingLayer.hpp"
#include "SimpleAudioEngine.h"
#include "SystemData.hpp"

Scene* Welcome::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Welcome ::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


bool Welcome::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Uibutton();
//    schedule(schedule_selector(GameScene::myClock),1.0f );
    scheduleUpdate();
    
//     UserDefault::getInstance()->setIntegerForKey("levl",3);
//    int a = UserDefault::getInstance()->getIntegerForKey("levl");
//    log("%d",a);
//    log("%s",UserDefault::getInstance()->getXMLFilePath().c_str());
    
    
//    roleturn();
    
    auto dispatcher=Director::getInstance()->getEventDispatcher();
    auto touchListener=EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan=CC_CALLBACK_2(Welcome::onTouchBegan, this);
    touchListener->onTouchMoved=CC_CALLBACK_2(Welcome::onTouchMoved, this);
    touchListener->onTouchEnded=CC_CALLBACK_2(Welcome::onTouchEnded, this);
    dispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    number=0;
    distance=0;
    return true;
}



bool Welcome::onTouchBegan(cocos2d::Touch* pthouch,cocos2d::Event* pEvent)
{
    
    auto point2=pthouch->getLocation();
    
    return true;
}

void Welcome::onTouchMoved(Touch *touch, Event *unused_event)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto point=touch->getDelta();
    log("%f",point.x);
    
    if (point.x>=300) {
        number++;
        if (number>3) {
            number=0;
        }
        
        
    }else if (point.x<=-300) {
        number--;
        if (number<-3) {
            number=0;
        }
        
    }
    switch (number) {
        case -1:
            nanzhu->removeFromParent();
            nanzhu=Sprite::create("ui/nanzhu4.png");
            nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
            nanzhu->setScale(0.46);
            nanzhu->setPosition(Vec2(bian1->getContentSize().width, visibleSize.height/10-50));
            addChild(nanzhu);
            break;
        case -2:
            nanzhu->removeFromParent();
            nanzhu=Sprite::create("ui/nanzhu3.png");
            nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
            nanzhu->setScale(0.46);
            nanzhu->setPosition(Vec2(bian1->getContentSize().width, visibleSize.height/10-50));
            addChild(nanzhu);
            break;
        case -3:
            nanzhu->removeFromParent();
            nanzhu=Sprite::create("ui/nanzhu2.png");
            nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
            //            nanzhu->setScale(0.46);
            nanzhu->setPosition(Vec2(bian1->getContentSize().width-nanzhu->getContentSize().width/8, visibleSize.height/10-30));
            addChild(nanzhu);
            break;
        case 0:
            nanzhu->removeFromParent();
            nanzhu=Sprite::create("ui/nanzhu1.png");
            nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
            //            nanzhu->setScale(0.46);
            nanzhu->setPosition(Vec2(bian1->getContentSize().width, visibleSize.height/5));
            addChild(nanzhu);
            break;
        case 1:
            nanzhu->removeFromParent();
            nanzhu=Sprite::create("ui/nanzhu2.png");
            nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
            //            nanzhu->setScale(0.46);
            nanzhu->setPosition(Vec2(bian1->getContentSize().width-nanzhu->getContentSize().width/8, visibleSize.height/10-30));
            addChild(nanzhu);
            break;
        case 2:
            nanzhu->removeFromParent();
            nanzhu=Sprite::create("ui/nanzhu3.png");
            nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
            nanzhu->setScale(0.46);
            nanzhu->setPosition(Vec2(bian1->getContentSize().width, visibleSize.height/10-50));
            addChild(nanzhu);
            break;
        case 3:
            nanzhu->removeFromParent();
            nanzhu=Sprite::create("ui/nanzhu4.png");
            nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
            nanzhu->setScale(0.46);
            nanzhu->setPosition(Vec2(bian1->getContentSize().width, visibleSize.height/10-50));
            addChild(nanzhu);
            break;
            
            
        default:
            break;
    }

    
   
   
    
    
}
void Welcome::onTouchEnded(cocos2d::Touch* pTouch,cocos2d::Event* pEvent)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto point=pTouch->getDelta();
//    point2= pTouch->getPreviousLocation();

    
    
    
}


void Welcome::onEnter()
{
    Layer::onEnter();
    
}

void Welcome::onExit()
{
    Layer::onExit();
//    _eventDispatcher->removeEventListener(_touchListener);
    
}

void Welcome::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    if (UserDefault::getInstance()->getBoolForKey(Music_Key)) {
        if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
    
        }else{
            SimpleAudioEngine::getInstance()->playBackgroundMusic("bgmusic.wav", true);
        }
        
    }
}

void Welcome::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
}

void Welcome::Uibutton()
{
    nodezuo=Node::create();
    addChild(nodezuo,1);
    
    nodeyou=Node::create();
    addChild(nodeyou,1);
    
    
    bian2=Sprite::create("ui/bian2.png");
    
   
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto bg=Sprite::create("ui/background2.png");
    bg->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(bg);
    
    bian1=Sprite::create("ui/bian1.png");
    bian1->setAnchorPoint(Vec2(0, 0.5));
    bian1->setPosition(Vec2((-bian1->getContentSize().width), visibleSize.height/2));
    addChild(bian1);
    
    auto bianmove= MoveTo::create(0.5, Vec2(0, visibleSize.height/2));
    bian1->runAction(bianmove);
    
    
    bian2->setAnchorPoint(Vec2(0, 0.5));
    bian2->setPosition(Vec2(visibleSize.width, visibleSize.height/2));
    addChild(bian2);
    
    auto moveto2= MoveTo::create(0.5, Vec2(visibleSize.width-bian2->getContentSize().width, visibleSize.height/2));
    auto wasesinein2=EaseSineIn::create(moveto2);
    bian2->runAction(wasesinein2);
    
    dakuang=Sprite::create("ui/dakuang.png");
    dakuang->setAnchorPoint(Vec2(1,0.5));
    dakuang->setPosition(Vec2(dakuang->getContentSize().width+visibleSize.width-bian2->getContentSize().width/2, 1.35*dakuang->getContentSize().height));
    nodeyou->addChild(dakuang,2);
    
    shangcheng = MenuItemImage::create("ui/UIbutton/shang1.png","ui/UIbutton/shang2.png",CC_CALLBACK_1(Welcome::shangchengye, this));
    shangcheng->setAnchorPoint(Vec2(0.4, 0.5));
    shangcheng->setPosition(Vec2(dakuang->getContentSize().width+visibleSize.width-bian2->getContentSize().height/2, visibleSize.height/4));
    
    shoucang = MenuItemImage::create("ui/UIbutton/shou1.png","ui/UIbutton/shou2.png",CC_CALLBACK_1(Welcome::shoucangguan, this));
    shoucang->setAnchorPoint(Vec2(0.4, 0.5));
    shoucang->setPosition(Vec2(dakuang->getContentSize().width+visibleSize.width-bian2->getContentSize().height/2,visibleSize.height-dakuang->getContentSize().height*1.1));
    
    
    shezhi = MenuItemImage::create("ui/UIbutton/she1.png","ui/UIbutton/she2.png",CC_CALLBACK_1(Welcome::shezhiye, this));
    shezhi->setTag(1004);
    shezhi->setAnchorPoint(Vec2(0, 0));
    shezhi->setPosition(Vec2(-bian1->getContentSize().width, 0.5*shezhi->getContentSize().height));
   
    
    juqing = MenuItemImage::create("ui/UIbutton/juqing1.png","ui/UIbutton/juqing2.png",CC_CALLBACK_1(Welcome::juqingmoshi, this));
    juqing->setTag(1003);
    juqing->setAnchorPoint(Vec2(0, 0));
    juqing->setPosition(Vec2(-bian1->getContentSize().width, 1.5*juqing->getContentSize().height));

    wuxian = MenuItemImage::create("ui/UIbutton/wu1.png","ui/UIbutton/wu2.png",CC_CALLBACK_1(Welcome::wuxianmoshi,this));
    wuxian->setTag(1002);
    wuxian->setAnchorPoint(Vec2(0, 0));
    wuxian->setPosition(Vec2(-bian1->getContentSize().width, 2.5*wuxian->getContentSize().height));
   
    
    auto menuzuo=Menu::create(wuxian,juqing,shezhi,NULL);
    menuzuo->setPosition(Vec2::ZERO);
    nodezuo->addChild(menuzuo);
    
    auto znodemove=MoveTo::create(0.7, Vec2(2*bian1->getContentSize().width, 0));
    auto znEaseBackOut=EaseBackOut::create(znodemove);
    nodezuo->runAction(znEaseBackOut);
    
    auto menuyou = Menu::create(shangcheng,shoucang, NULL);
    menuyou->setPosition(Vec2::ZERO);
    nodeyou->addChild(menuyou);
    
    auto ynodemove = MoveTo::create(0.7, Vec2(-dakuang->getContentSize().width, 0));
    auto ynEaseBackOut=EaseBackOut::create(ynodemove);
    nodeyou->runAction(ynEaseBackOut);
    
    
    
    // 经验条
    
    auto lvback=Sprite::create("ui/lvback.png");
    lvback->setAnchorPoint(Vec2(1, 0.9));
    lvback->setPosition(Vec2(dakuang->getContentSize().width , dakuang->getContentSize().height));
    dakuang->addChild(lvback);
    
    auto exp=Sprite::create("ui/exp.png");
    ProgressTimer* ct=ProgressTimer::create(exp);
    ct->setAnchorPoint(Vec2(0.5, 0.35));
    ct->setPosition(lvback->getPosition().x-lvback->getContentSize().width/2,lvback->getPosition().y-lvback->getContentSize().height/2);
    ct->setTag(50);
    dakuang->addChild(ct);
    ct->setReverseProgress(false);
    ct->setPercentage(80);
    ct->setType(ProgressTimer::Type::RADIAL);
    
    //男主
    nanzhu=Sprite::create("ui/nanzhu1.png");
    nanzhu->setAnchorPoint(Vec2(0.15, 0.5));
//    nanzhu->setScale(0.46);
    nanzhu->setDirty(true);
    
    nanzhu->setPosition(Vec2(-nanzhu->getContentSize().width, visibleSize.height/10-50));
    addChild(nanzhu);
    auto nanzhumove=MoveTo::create(0.5, Vec2(bian1->getContentSize().width, visibleSize.height/5 ));
    nanzhu->runAction(nanzhumove);
    
}

void Welcome::update(float dt)
{
//    i++;
//    log("%d",i);
}

void Welcome::juqingmoshi(Ref* pSender)
{
    
    log("剧情模式");
    Director::getInstance()->replaceScene(TransitionFade::create(0.38, TheDrama::createScene()));
    removebtn();
}

void Welcome::wuxianmoshi(Ref* psender)
{
    log("无限模式");
    
    Director::getInstance()->replaceScene(TransitionFade::create(0.8, PlayLayer::createScene()));
    
    removebtn();
}

void Welcome:: shangchengye(Ref* psender)
{
    log("商城");
    
    Director::getInstance()->replaceScene(TransitionFade::create(0.8, ShopStore::createScene()));
    removebtn();
}

void Welcome::shoucangguan(Ref* psender)
{
    log("收藏馆");
    Director::getInstance()->replaceScene(TransitionFade::create(1.0f, TheCollect::createScene()));
    removebtn();
}

void Welcome::shezhiye(Ref* psender)
{
    
    log("设置");
    Director::getInstance()->pushScene(TransitionFade::create(0.5f, SettingLayer::createScene()));
}



void Welcome:: removebtn()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto movebian1=MoveTo::create(0.5, Vec2(-(bian1->getContentSize().width), visibleSize.height/2));
    bian1->runAction(movebian1);
    
    auto movebian2=MoveTo::create(0.5, Vec2(visibleSize.width, visibleSize.height/2));
    bian2->runAction(movebian2);
    
    auto ynmoveout=MoveTo::create(0.5, Vec2(0, 0));
    nodeyou->runAction(ynmoveout);
    
    auto znmoveout=MoveTo::create(0.5, Vec2(-bian1->getContentSize().width, 0));
    nodezuo->runAction(znmoveout);
    
}










