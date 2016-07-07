//
//  TheCollect.hpp
//  Lioner
//
//  Created by 张伟 on 16/3/20.
//
//

#ifndef TheCollect_hpp
#define TheCollect_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC_EXT;
USING_NS_CC;
class TheCollect : public cocos2d::Layer, public TableViewDelegate , public TableViewDataSource
{
public:
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(TheCollect);
    
//    Sprite *sprite[5];
    Sprite* bgkuang;
    TableView* table;
    void tableview();
    virtual Size tableCellSizeForIndex(TableView *table, ssize_t idx) ; // 定义cell大小
    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);// 每个cell显示多少内容
    virtual ssize_t numberOfCellsInTableView(TableView *table);  //显示多少行
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    virtual void tableCellHighlight(TableView* table, TableViewCell* cell);
    virtual void tableCellUnhighlight(TableView* table, TableViewCell* cell);
    
    void cradflip();
    void createcard();
    void menuItem1Callback(cocos2d::Ref* pSender);
    void menuItem2Callback(cocos2d::Ref* pSender);
    void menuItem3Callback(cocos2d::Ref* pSender);
    void menuItem4Callback(cocos2d::Ref* pSender);
    void menuItem5Callback(cocos2d::Ref* pSender);
    void hideAllSprite();
    cocos2d::Sprite *sprite[5];
    void backmenuItemCallback(cocos2d::Ref* pSender);
    
};

#endif /* TheCollect_hpp */
