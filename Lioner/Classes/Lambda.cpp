//
//  Lambda.cpp
//  Lioner
//
//  Created by 张伟 on 16/5/30.
//
//

#include "Lambda.hpp"
Lambda::Lambda()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("shop_npc.plist","shop_npc.pvr.ccz");
    Sprite::initWithSpriteFrameName("npc_1001.png");
    
    
}
void Lambda::action1()
{
    /*
     //方式三,通过.plist 文件来创建
     auto cache = SpriteFrameCache::getInstance();
     cache->addSpriteFramesWithFile("animate.plist");
     
     auto sprite3 = Sprite::createWithSpriteFrameName("grossini_dance_05.png");
     sprite3->setPosition(Vec2(visibleSize.width*0.7, visibleSize.height/2));
     this->addChild(sprite3);
     
     Vector<cocos2d::SpriteFrame *> arr;
     char str[100] = {0};
     for (int i=1; i<15; i++)
     {
     sprintf(str, "grossini_dance_%02d.png", i);
     auto frame_2 = cache->SpriteFrameCache::getInstance()->getSpriteFrameByName(str);   //3.2版本有改变
     arr.pushBack(frame_2);
     }
     
     auto animation3 = Animation::createWithSpriteFrames(arr, 0.2f);     //此处也不要忘记加上时间间隔参数
     sprite3->runAction(RepeatForever::create(Animate::create(animation3)));
     */
//    __Array *plistArray= __Array::create();
    Vector<cocos2d::SpriteFrame *> plistArray;
    SpriteFrameCache* cache =SpriteFrameCache::getInstance();
    char name[50];
    for(int i=1;i<=11;i++)
    {
        sprintf(name, "npc_10%02d.png",i);
//        if(i<10)
//        {
//            sprintf(name,"npc_100%d.png",i);
//        }
//        else
//        {
//            sprintf(name,"npc_10%d.png",i);
//        }
//        SpriteFrame* frame =cache->spriteFrameByName(name);
        SpriteFrame* frame =cache->getSpriteFrameByName(name);
        plistArray.pushBack(frame);
    }
    Animation *plitAnimation=Animation::createWithSpriteFrames(plistArray,0.2f);
    Animate *plitAnimate=Animate::create(plitAnimation);
    this->runAction(RepeatForever::create(plitAnimate));

}













