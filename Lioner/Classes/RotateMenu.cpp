//
//  RotateMenu.cpp
//  3Dmenu
//
//  Created by 张伟 on 16/3/29.
//
//

#include "RotateMenu.hpp"
#include <math.h>
#define PI acos(-1)

bool RotateMenu::init()
{
    if (!Layer::init())
        return false;
    _angle = 0.0;
    this->ignoreAnchorPointForPosition(false);
    _selectedItem = nullptr;
    Size s = Director::getInstance()->getWinSize();
    this->setContentSize(s/5*4);
    this->setAnchorPoint(Vec2(0.5f, 0.5f));
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(RotateMenu::onTouchBegan,this);
    listener->onTouchMoved = CC_CALLBACK_2(RotateMenu::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(RotateMenu::onTouchEnded, this);
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
};

void RotateMenu::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    
    
    //选中的边框
    auto BK1 = Sprite::create("flashs.png");
    MenuItem* si=getCurrentItem();
    auto menuSize =getContentSize();
    
    Vec2 v=si->getPosition();
    BK1->setPosition(Vec2(v.x,v.y));
    //BK1->setScale(0.76, 0.76);
    BK1->setTag(1001);
    this->addChild(BK1);
    
}

void RotateMenu::addMenuItem(cocos2d::MenuItem *item){
    item->setPosition(this->getContentSize()/2);
    this->addChild(item);
    _items.pushBack(item);
    setUnitAngle(2 * PI / _items.size()); //设置单位弧度
    reset();
    updatePositionWithAnimation();
    return;
}
void RotateMenu::updatePosition(){//更新位置
    auto menuSize = getContentSize();
    auto disY = menuSize.height / 8;
    auto disX = menuSize.width / 3;
    for (int i = 0; i < _items.size(); i++){
        float x = menuSize.width / 2 + disX*sin(i*_unitAngle+getAngle());
        float y = menuSize.height / 2 - disY*cos(i*_unitAngle + getAngle());
        _items.at(i)->setPosition(Vec2(x, y));
        _items.at(i)->setZOrder(-(int)y);
        //Opacity  129~255
        _items.at(i)->setOpacity(192 + 63 * cos(i*_unitAngle + getAngle()));
        _items.at(i)->setScale(0.75 + 0.25*cos(i*_unitAngle + getAngle()));
    }
    return;
}
void RotateMenu::updatePositionWithAnimation(){//更新位置，有动画
    //先停止所有可能存在的动作
    for (int i = 0; i < _items.size(); i++)
        _items.at(i)->stopAllActions();
    auto menuSize = getContentSize();
    auto disY = menuSize.height / 8;
    auto disX = menuSize.width / 3;
    for (int i = 0; i < _items.size(); i++){
        float x = menuSize.width / 2 + disX*sin(i*_unitAngle + getAngle());
        float y = menuSize.height / 2 - disY*cos(i*_unitAngle + getAngle());
        auto moveTo = MoveTo::create(animationDuration, Vec2(x, y));
        _items.at(i)->runAction(moveTo);
        //Opacity  129~255
        auto fadeTo = FadeTo::create(animationDuration, (192 + 63 * cos(i*_unitAngle + getAngle())));
        _items.at(i)->runAction(fadeTo);
        //缩放比例  0.5~1
        auto scaleTo = ScaleTo::create(animationDuration, 0.75 + 0.25*cos(i*_unitAngle + getAngle()));
        _items.at(i)->runAction(scaleTo);
        _items.at(i)->setZOrder(-(int)y);
    }
    scheduleOnce(schedule_selector(RotateMenu::actionEndCallBack), animationDuration);
    return;
}


void RotateMenu::reset(){ //重置  操作有旋转角度设为0
    _angle = 0;
}
void RotateMenu::setAngle(float angle){ //设置角度 弧度
    this->_angle = angle;
}
float RotateMenu::getAngle(){
    return _angle;
}
void RotateMenu::setUnitAngle(float angle){//设置单位角度 弧度
    _unitAngle = angle;
}
float RotateMenu::getUnitAngle(){
    return _unitAngle;
}

float RotateMenu::disToAngle(float dis){//滑动距离转换角度,转换策略为  移动半个Menu.width等于_unitAngle
    float width = this->getContentSize().width / 2;
    return dis / width*getUnitAngle();
}

MenuItem * RotateMenu::getCurrentItem(){//返回被选中的item
    if (_items.size() == 0)
        return nullptr;
    //这里实际加上了0.1getAngle(),用来防止精度丢失
    int  index = (int)((2 * PI - getAngle()) / getUnitAngle()+0.1*getUnitAngle());
    index %= _items.size();
    return _items.at(index);
}

bool RotateMenu::onTouchBegan(Touch* touch, Event* event){
    
    //先停止所有可能存在的动作
    for (int i = 0; i < _items.size(); i++)
        _items.at(i)->stopAllActions();
//    if (_selectedItem)
//        _selectedItem->unselected();
    auto position = this->convertToNodeSpace(touch->getLocation());
    auto size = this->getContentSize();
    auto rect = Rect(0, 0, size.width, size.height);
    this->getChildByTag(1001)->setVisible(false);
    if (rect.containsPoint(position)){
        return true;
    }
    return false;
}
void RotateMenu::onTouchEnded(Touch* touch, Event* event){
    auto xDelta = touch->getLocation().x - touch->getStartLocation().x;
    rectify(xDelta>0);
    if (disToAngle(fabs(xDelta))<getUnitAngle() / 6&&_selectedItem)
        _selectedItem->activate();
    updatePositionWithAnimation();
    return;
}
void RotateMenu::onTouchMoved(Touch* touch, Event* event){
    auto angle = disToAngle(touch->getDelta().x);
    setAngle(getAngle() + angle);
    updatePosition();
    return;
}

void RotateMenu::rectify(bool forward){ //位置矫正  修改角度 forward为移动方向  当超过1/3，进1
    //true 为正向  false 负
    auto angle = getAngle();
    while (angle<0)
        angle += PI * 2;
    while (angle>PI * 2)
        angle -= PI * 2;
    if(forward>0)
        angle = ((int)((angle + getUnitAngle() / 3*2) / getUnitAngle()))*getUnitAngle();
    else
        angle = ((int)((angle + getUnitAngle() / 3 ) / getUnitAngle()))*getUnitAngle();
    setAngle(angle);
}

void RotateMenu::actionEndCallBack(float dx){//动画完结调用函数
    _selectedItem = getCurrentItem();
    if(_selectedItem){
    this->getChildByTag(1001)->setVisible(true);
    }
//
}










