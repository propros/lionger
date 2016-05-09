//
//  ThePlot.cpp
//  Lioner
//
//  Created by 张伟 on 16/3/20.
//
//

#include "TheDrama.hpp"
#include "RotateMenu.hpp"
#include "SelectDrama.hpp"
#include "Welcome.hpp"
#include "Talking.hpp"

Scene* TheDrama :: createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TheDrama ::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool TheDrama:: init()
{
    if (!Layer::init()) {
        return false;
    }
    Size visiblesize=Director::getInstance()->getVisibleSize();
    
    auto background2=Sprite::create("ui/background2.png");
    background2->setPosition(Vec2(visiblesize.width/2, visiblesize.height/2));
    addChild(background2);
    

    bgkuang=Sprite::create("bgkuang.png");
    bgkuang->setPosition(Vec2(visiblesize.width/2, visiblesize.height/2));
    addChild(bgkuang,3);
    bgkuang->setVisible(false);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto item1 = MenuItemImage::create("item1_1.png", "item1_0.png", CC_CALLBACK_1(TheDrama::menuItem1Callback, this));
    item1->setTag(1001);
    auto item2 = MenuItemImage::create("item2_1.png", "item2_0.png", CC_CALLBACK_1(TheDrama::menuItem2Callback, this));
    item2->setTag(1002);
    auto item3 = MenuItemImage::create("item3_1.png", "item3_0.png", CC_CALLBACK_1(TheDrama::menuItem3Callback, this));
    item3->setTag(1003);
    auto item4 = MenuItemImage::create("item4_1.png", "item4_0.png", CC_CALLBACK_1(TheDrama::menuItem4Callback, this));
    item4->setTag(1004);
    auto item5 = MenuItemImage::create("item5_1.png", "item5_0.png", CC_CALLBACK_1(TheDrama::menuItem5Callback, this));
    item5->setTag(1005);
    
    auto back = MenuItemImage::create("backl.png", "backd.png", CC_CALLBACK_1(TheDrama::backmenuItemCallback, this));
    back->setPosition(Vec2(back->getContentSize().width/2, visibleSize.height-back->getContentSize().height/2));

    Menu *buttonmenu = Menu::create(back,NULL);
    buttonmenu->setPosition(Point::ZERO);
    addChild(buttonmenu,3);
    
    RotateMenu *menu = RotateMenu::create();
    menu->addMenuItem(item1);
    menu->addMenuItem(item2);
    menu->addMenuItem(item3);
    menu->addMenuItem(item4);
    menu->addMenuItem(item5);
    menu->setPosition(visibleSize/2);
    this->addChild(menu, 2);
    
    
    for (int i = 0; i < 5; i++){
        char str[20];
        sprintf(str, "item%d.jpg", i + 1);
        sprite[i] = Sprite::create(str);
        sprite[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
        sprite[i]->setPosition(visibleSize / 2);
        this->addChild(sprite[i]);
    }
    hideAllSprite();
    tableview();
    return true;
}

void TheDrama::tableview()
{
    Size visiblesize=Director::getInstance()->getVisibleSize();
    auto sprite=Sprite::create("ui/UIbutton/table1.png");

    
    table=TableView::create(this,Size(sprite->getContentSize().width,5.5*sprite->getContentSize().height));
    table->setDelegate(this);
    table->setDirection(TableView::Direction::VERTICAL);
    table->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    table->setPosition(Point(bgkuang->getPositionX()-bgkuang->getContentSize().width/2,bgkuang->getPositionY()-bgkuang->getContentSize().height/2));

    this->addChild(table,4);
    table->setVisible(false);
    table->reloadData();
    
}

Size TheDrama::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
    auto cellsize=Sprite::create("ui/UIbutton/table1.png");
    return Size(cellsize->getContentSize().width, cellsize->getContentSize().height);
}// 定义cell大小

TableViewCell* TheDrama::tableCellAtIndex(TableView *table, ssize_t idx)
{
    
    TableViewCell *cell = table->dequeueCell();
    
    cell = new TableViewCell();
    cell->autorelease();

    
    ValueVector vec = FileUtils::getInstance()->getValueVectorFromFile("data.plist");
    long idx0=0;
    log("idx:%ld",idx);
    if (idx==0) {
        idx0=idx;
    }else{
        idx0=idx*3;
    }
    long idx1=idx0+1;
    
    auto bg=Sprite::create("ui/UIbutton/table1.png");
    bg->setAnchorPoint(Vec2(0, 0));
    bg->setPosition(Vec2::ZERO);
    bg->setTag(789);
    cell->addChild(bg,0);
    
    std::string vec_1=vec.at(idx1).asString();
    Sprite* imge_1=Sprite::create(vec_1);
    imge_1->setAnchorPoint(Vec2(0, 0));
    imge_1->setPosition(Point(10, 0));
    cell->addChild(imge_1);
    return cell;
    
}// 每个cell显示多少内容

ssize_t TheDrama::numberOfCellsInTableView(TableView *table)
{
    return 6;
}//显示多少行

void TheDrama::tableCellTouched(TableView* table, TableViewCell* cell)
{
    auto scene=Scene::create();
    auto ss=SelectDrama::create();
    ss->setstring((int)cell->getIdx()+1);
    
    scene->addChild(ss);
    
    log("%zd:touched",cell->getIdx()+1);
    
    auto move= MoveTo::create(cell->getIdx(), Vec2(100, cell->getPositionY()));
    cell->runAction(move);
    
    Director::getInstance()->replaceScene(TransitionFade::create(0.8, Talking::createScene(),Color3B(100, 100, 100)));
    
    
    
    
    
}//cell 点击以后的回调函数

void TheDrama::tableCellHighlight(TableView* table, TableViewCell* cell)
{
    auto atexture=Director::getInstance()->getTextureCache()->addImage("ui/UIbutton/table2.png");
    auto sp=(Sprite*)cell->getChildByTag(789);
    sp->setTexture(atexture);
    
}

void TheDrama::tableCellUnhighlight(TableView* table, TableViewCell* cell)
{
    auto atexture=Director::getInstance()->getTextureCache()->addImage("ui/UIbutton/table1.png");
    auto sp=(Sprite*)cell->getChildByTag(789);
    sp->setTexture(atexture);
}


void TheDrama::menuItem1Callback(cocos2d::Ref* pSender){
    hideAllSprite();
    bgkuang->setVisible(true);
    table->setVisible(true);
//    sprite[0]->setVisible(true);
}
void TheDrama::menuItem2Callback(cocos2d::Ref* pSender){
    hideAllSprite();
     bgkuang->setVisible(true);
    sprite[1]->setVisible(true);
}
void TheDrama::menuItem3Callback(cocos2d::Ref* pSender){
    hideAllSprite();
     bgkuang->setVisible(true);
    sprite[2]->setVisible(true);
}
void TheDrama::menuItem4Callback(cocos2d::Ref* pSender){
    hideAllSprite();
     bgkuang->setVisible(true);
    sprite[3]->setVisible(true);
}
void TheDrama::menuItem5Callback(cocos2d::Ref* pSender){
    hideAllSprite();
     bgkuang->setVisible(true);
    sprite[4]->setVisible(true);
}

void TheDrama::hideAllSprite(){
    for (auto p : sprite){
        if (p->isVisible())
            p->setVisible(false);
    }
}

void TheDrama::backmenuItemCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.1, Welcome::createScene()));
}










