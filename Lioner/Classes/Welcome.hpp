//
//  Welcome.hpp
//  Lioner
//
//  Created by 张伟 on 16/3/3.
//
//

#ifndef Welcome_hpp
#define Welcome_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;
USING_NS_CC;

class Welcome : public cocos2d::Layer
{
public:
    
    static cocos2d::Scene* createScene();
    
    virtual bool init()override;
    virtual void update(float dt) override;
    
    virtual void onEnter()override;
    virtual void onEnterTransitionDidFinish()override;
    virtual void onExit()override;
    virtual void onExitTransitionDidStart()override;
    
    
    void Uibutton();
    
    Node* nodezuo;
    Node* nodeyou;
    int i;
    
    void shangchengye(Ref* pSender);
    void wuxianmoshi(Ref* psender);
    void shoucangguan(Ref* psender);
    void shezhiye(Ref* psender);
    void juqingmoshi(Ref* psender);
    void removebtn();
    void menuleave();
    
    
    
    MenuItemImage* shoucang;
    MenuItemImage* juqing;
    MenuItemImage* shangcheng;
    MenuItemImage* shezhi;
    MenuItemImage* wuxian;
    MenuItemImage* item1;

    Sprite* bian1;
    Sprite* bian2;
    Sprite* sprite;
    Sprite* dakuang;
    void out(float t);
    CREATE_FUNC(Welcome);
};



#endif /* Welcome_hpp */
