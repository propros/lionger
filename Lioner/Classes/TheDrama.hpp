
#ifndef TheDrama_hpp
#define TheDrama_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "cocos-ext.h"
//#include <extensions/cocos-ext.h>
USING_NS_CC;
USING_NS_CC_EXT;
class TheDrama : public cocos2d::Layer,public TableViewDataSource , public TableViewDelegate
{
public:
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(TheDrama);
    
    __String* string;
    
    void tableview();
    
    virtual Size tableCellSizeForIndex(TableView *table, ssize_t idx) ; // 定义cell大小
    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);// 每个cell显示多少内容
    virtual ssize_t numberOfCellsInTableView(TableView *table);  //显示多少行
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    virtual void tableCellHighlight(TableView* table, TableViewCell* cell);
    virtual void tableCellUnhighlight(TableView* table, TableViewCell* cell);
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    void menuItem1Callback(cocos2d::Ref* pSender);
    void menuItem2Callback(cocos2d::Ref* pSender);
    void menuItem3Callback(cocos2d::Ref* pSender);
    void menuItem4Callback(cocos2d::Ref* pSender);
    void menuItem5Callback(cocos2d::Ref* pSender);
    void backmenuItemCallback(cocos2d::Ref* pSender);
    void hideAllSprite();
    cocos2d::Sprite *sprite[5];
    Sprite* bgkuang;
    TableView* table;

    
};

#endif


