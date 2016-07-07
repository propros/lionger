//
//  TheCollect.cpp
//  Lioner
//
//  Created by 张伟 on 16/3/20.
//
//

#include "TheCollect.hpp"
#include "SendCardlayer.hpp"
#include "Welcome.hpp"
#include "LoLMenu.hpp"
const char* ROWS_KEY = "row";
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
    addChild(background2,-2);
    
    auto back = MenuItemImage::create("backl.png", "backd.png", CC_CALLBACK_1(TheCollect::backmenuItemCallback, this));
    back->setPosition(Vec2(back->getContentSize().width/2, visiblesize.height-back->getContentSize().height/2));
    
    Menu *buttonmenu = Menu::create(back,NULL);
    buttonmenu->setPosition(Point::ZERO);
    addChild(buttonmenu,3);
    
    
//    auto sendLayer = SendCardlayer::create();
//    this->addChild(sendLayer);
    
    bgkuang=Sprite::create("bgkuang.png");
    bgkuang->setPosition(Vec2(visiblesize.width/2, visiblesize.height/2));
    addChild(bgkuang,3);
    bgkuang->setVisible(false);
    

//    createcard();
//    cradflip();
    tableview();
    
        return true;
}

void TheCollect::tableview()
{
    Size visiblesize=Director::getInstance()->getVisibleSize();
    auto sprite=Sprite::create("ui/UIbutton/table1.png");
    
    
    table=TableView::create(this,Size(6*sprite->getContentSize().width,sprite->getContentSize().height));
    table->setDelegate(this);
    table->setDirection(TableView::Direction::HORIZONTAL);
    //    table->setVerticalFillOrder(TableView::VerticalFillOrder::TOP_DOWN);
    table->setPosition(Point(bgkuang->getPositionX()-bgkuang->getContentSize().width/2,bgkuang->getPositionY()-bgkuang->getContentSize().height/2));
    
    this->addChild(table,4);
//    table->setVisible(false);
    table->reloadData();
    
}

Size TheCollect::tableCellSizeForIndex(TableView *table, ssize_t idx)
{
    auto cellsize=Sprite::create("ui/UIbutton/table1.png");
    return Size(cellsize->getContentSize().width, cellsize->getContentSize().height);
}// 定义cell大小

TableViewCell* TheCollect::tableCellAtIndex(TableView *table, ssize_t idx)
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

ssize_t TheCollect::numberOfCellsInTableView(TableView *table)
{
    return 6;
}//显示多少行

void TheCollect::tableCellTouched(TableView* table, TableViewCell* cell)
{
    //    auto scene=Scene::create();
    //    auto ss=Talking::create();
    //    ss->setstring((int)cell->getIdx()+1);
    //    scene->addChild(ss);
    UserDefault::getInstance()->setIntegerForKey(ROWS_KEY, (float)cell->getIdx()+1);
    
    log("%zd:touched",cell->getIdx()+1);
    
//    Director::getInstance()->replaceScene(TransitionFade::create(0.8, Talking::createScene(),Color3B(100, 100, 100)));
    
    
}//cell 点击以后的回调函数

void TheCollect::tableCellHighlight(TableView* table, TableViewCell* cell)
{
    auto atexture=Director::getInstance()->getTextureCache()->addImage("ui/UIbutton/table2.png");
    auto sp=(Sprite*)cell->getChildByTag(789);
    sp->setTexture(atexture);
    
}

void TheCollect::tableCellUnhighlight(TableView* table, TableViewCell* cell)
{
    auto atexture=Director::getInstance()->getTextureCache()->addImage("ui/UIbutton/table1.png");
    auto sp=(Sprite*)cell->getChildByTag(789);
    sp->setTexture(atexture);
}

void TheCollect::createcard()
{
    Size visiblesize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //创建发牌层
    auto senfLayerBtn = MenuItemFont::create("创建发牌层", [&](Ref * obj)
                                             {
                                                 auto sendLayer = SendCardlayer::create();
                                                 this->addChild(sendLayer);
                                             });
    senfLayerBtn->setPosition(Vec2(visiblesize.width * 0.8,visiblesize.height * 0.8));
    auto pMenu = Menu::create(senfLayerBtn,NULL);
    pMenu->setPosition(Vec2::ZERO);
    this->addChild(pMenu);
}

void TheCollect::cradflip()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto item1 = MenuItemImage::create("item1_0.png", "item1_0.png", CC_CALLBACK_1(TheCollect::menuItem1Callback, this));
    auto item2 = MenuItemImage::create("item2_0.png", "item2_0.png", CC_CALLBACK_1(TheCollect::menuItem2Callback, this));
    auto item3 = MenuItemImage::create("item3_0.png", "item3_0.png", CC_CALLBACK_1(TheCollect::menuItem3Callback, this));
    auto item4 = MenuItemImage::create("item4_0.png", "item4_0.png", CC_CALLBACK_1(TheCollect::menuItem4Callback, this));
    auto item5 = MenuItemImage::create("item5_0.png", "item5_0.png", CC_CALLBACK_1(TheCollect::menuItem5Callback, this));
    
    LoLMenu *menu = LoLMenu::create();
    
    menu->addMenuItem(item1);
    menu->addMenuItem(item2);
    menu->addMenuItem(item3);
    menu->addMenuItem(item4);
    menu->addMenuItem(item5);
    
    menu->setPosition(visibleSize / 2);
    this->addChild(menu, 2);
    
    
    for (int i = 0; i < 5; i++){
        char str[100];
        sprintf(str, "role%d.jpg", i + 1);
        sprite[i] = Sprite::create(str);
        sprite[i]->setAnchorPoint(Vec2(0.5f, 0.5f));
        sprite[i]->setPosition(visibleSize / 2);
        this->addChild(sprite[i]);
    }
    hideAllSprite();

}

void TheCollect::menuItem1Callback(cocos2d::Ref* pSender){
    hideAllSprite();
    sprite[0]->setVisible(true);
}
void TheCollect::menuItem2Callback(cocos2d::Ref* pSender){
    hideAllSprite();
    sprite[1]->setVisible(true);
}
void TheCollect::menuItem3Callback(cocos2d::Ref* pSender){
    hideAllSprite();
    sprite[2]->setVisible(true);
}
void TheCollect::menuItem4Callback(cocos2d::Ref* pSender){
    hideAllSprite();
    sprite[3]->setVisible(true);
}
void TheCollect::menuItem5Callback(cocos2d::Ref* pSender){
    hideAllSprite();
    sprite[4]->setVisible(true);
}

void TheCollect::hideAllSprite(){
    for (auto p : sprite){
        if (p->isVisible())
            p->setVisible(false);
    }
}

void TheCollect::backmenuItemCallback(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(TransitionFade::create(0.1, Welcome::createScene()));
}

