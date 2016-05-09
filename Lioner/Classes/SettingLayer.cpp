//
//  SettingLayer.cpp
//  Lioner
//
//  Created by 张伟 on 16/3/23.
//
//

#include "SettingLayer.hpp"
#include "Welcome.hpp"
#include "SystemData.hpp"

cocos2d::Scene* SettingLayer::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SettingLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}
bool SettingLayer::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    
    
    Sprite *bg = Sprite::create("ui/background2.png");
    
    bg->setPosition(Point(origin.x + visibleSize.width/2,
                          origin.y + visibleSize.height /2));
    this->addChild(bg);
    
    auto soundOnMenuItem = MenuItemImage::create(
                                                 "on.png",
                                                 "on.png");
    auto soundOffMenuItem = MenuItemImage::create(
                                                  "off.png",
                                                  "off.png");
    
    auto soundToggleMenuItem = MenuItemToggle::createWithCallback(
                                                                  CC_CALLBACK_1(::SettingLayer::menuSoundToggleCallback, this),
                                                                  soundOffMenuItem,
                                                                  soundOnMenuItem,
                                                                  NULL);
    soundToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Point(818, 220)));
    
    //背景音乐
    auto bgmusic=Label::createWithSystemFont("背景音乐", "", 40);
    bgmusic->setPosition(Vec2(600, 362));
    addChild(bgmusic);
    
    auto musicOnMenuItem  = MenuItemImage::create(
                                                  "on.png",
                                                  "on.png");
    auto musicOffMenuItem  = MenuItemImage::create(
                                                   "off.png",
                                                   "off.png");
    auto musicToggleMenuItem = MenuItemToggle::createWithCallback(
                                                                  CC_CALLBACK_1(::SettingLayer::menuMusicToggleCallback, this),
                                                                  musicOffMenuItem,
                                                                  musicOnMenuItem,
                                                                  NULL );
    musicToggleMenuItem->setPosition(Director::getInstance()->convertToGL(Point(818, 362)));
    
    
    //back按钮
    auto backMenuItem  = MenuItemImage::create(
                                             "backl.png",
                                             "backd.png",
                                             CC_CALLBACK_1(SettingLayer::menuOkCallback, this));
    
    
    backMenuItem->setPosition(Vec2(backMenuItem->getContentSize().width, backMenuItem->getContentSize().height));
    
    
    Menu* mn = Menu::create(soundToggleMenuItem, musicToggleMenuItem,backMenuItem, NULL);  
    mn->setPosition(Point::ZERO);  
    this->addChild(mn);
    
    UserDefault* defaults = UserDefault::getInstance();
    
    if (defaults->getBoolForKey(Music_Key)) {
        musicToggleMenuItem->setSelectedIndex(0);
    }else{
        musicToggleMenuItem->setSelectedIndex(1);
    }
    
    if (defaults->getBoolForKey(Effect_Key)) {
        soundToggleMenuItem->setSelectedIndex(0);
    }else{
        soundToggleMenuItem->setSelectedIndex(1);
    }
    
    
    return true;
}
void SettingLayer::onEnter()
{
    Layer::onEnter();
    log("Setting onEnter");
}
void SettingLayer::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    log("Setting onEnterTransitionDidFinish");
    //播放
    if (UserDefault::getInstance()->getBoolForKey(Music_Key)) {
        if (SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying()) {
        }else{
             SimpleAudioEngine::getInstance()->playBackgroundMusic("bgmusic.wav", true);
        }
    }
    
}
void SettingLayer::onExit()
{
    Layer::onExit();
    log("Setting onExit");
}
void SettingLayer::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
    log("Setting onExitTransitionDidStart");
}
void SettingLayer::cleanup()
{
    Layer::cleanup();
    
    log("Setting cleanup");
    //停止
//    SimpleAudioEngine::getInstance()->stopBackgroundMusic("sound/Synth.mp3");
}

void SettingLayer::menuSoundToggleCallback(cocos2d::Ref* pSender)
{
    auto soundToggleMenuItem = (MenuItemToggle*)pSender;
    log("soundToggleMenuItem %d", soundToggleMenuItem->getSelectedIndex());
    
    UserDefault *defaults=UserDefault::getInstance();
    if (defaults->getBoolForKey(Effect_Key)) {
        defaults->setBoolForKey(Effect_Key, false);
    }else{
        defaults->getBoolForKey(Effect_Key,true);
        SimpleAudioEngine::getInstance()->playEffect("effect.wav");
    }
}
void SettingLayer::menuMusicToggleCallback(cocos2d::Ref* pSender)
{
    auto musicToggleMenuItem = (MenuItemToggle*)pSender;
    log("musicToggleMenuItem %d", musicToggleMenuItem->getSelectedIndex());
    
    UserDefault* defaults=UserDefault::getInstance();
    if (defaults->getBoolForKey(Music_Key)) {
        defaults->setBoolForKey(Music_Key, false);
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
    }else{
        defaults->setBoolForKey(Music_Key, true);
        SimpleAudioEngine::getInstance()->playBackgroundMusic("bgmusic.wav");
    }

}
void SettingLayer::menuOkCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
    UserDefault* defaults=UserDefault::getInstance();
    if (defaults->getBoolForKey(Effect_Key)) {
        SimpleAudioEngine::getInstance()->playEffect("sound/Blip.wav");
    }
    log("fanhui;");
}





























