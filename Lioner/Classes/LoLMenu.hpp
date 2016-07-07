//
//  LoLMenu.hpp
//  LoLMenu
//
//  Created by 张伟 on 16/5/24.
//
//
/*
 *模仿英雄联盟的皮肤选择菜单
 *不同点在于，英雄联盟当皮肤过多时，部分皮肤会移出边缘，不显示
 *我会显示所以菜单项，向边缘移动会不断减缓
 */

#ifndef LoLMenu_hpp
#define LoLMenu_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class LoLMenu:public Layer
{
public:
    //构造方法
    
    CREATE_FUNC(LoLMenu);
    
    //添加菜单项
    
    void addMenuItem(cocos2d::MenuItem *item);
    
    //更新位置
    
    void updatePosition();
    
    //更新位置，有动画
    
    void updatePositionWithAnimation();
    
    //位置矫正  修改位置forward为移动方向  当超过1/3，进1
    
    //true 为正向  false 负
   
    void rectify(bool forward);
    
    //初始化
    
    virtual bool init();
    
    //重置  显示所引号设置为0
    
    void reset();
    
private:
    
    //设置当前显示索引
    
    void setIndex(int index);
    
    //设置当前显示菜单项的索引号
    
    float getIndex();
    
    //返回被选中的item
    
    cocos2d::MenuItem * getCurrentItem();
  
    //数学计算式width*index/(abs(index)+CALC_A) ,其中CALC_A为常数
   
    float calcFunction(float index, float width);
    
private:
   
    //菜单菜单项的索引号
    
    float _index;
    
    //上一次菜单项的索引号
    
    float _lastIndex;
    
    //菜单项集合,_children顺序会变化，新建数组保存顺序
    
    cocos2d::Vector<cocos2d::MenuItem *> _items;
    
    //监听函数
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
   
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    
    //动画完结调用函数，这个主要是确定哪一个菜单项在前面
    
    void actionEndCallBack(float dx);
    
    //当前被选择的item
    
    cocos2d::MenuItem *_selectedItem;
};

#endif /* LoLMenu_hpp */
