//
//  ShopStore.hpp
//  Lioner
//
//  Created by 张伟 on 16/3/18.
//
//

#ifndef ShopStore_hpp
#define ShopStore_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "Lambda.hpp"
USING_NS_CC;
class ShopStore : public cocos2d::Layer
{
public:
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // implement the "static node()" method manually
    CREATE_FUNC(ShopStore);
    Lambda* lambda;
    
    
    void backmenuItemCallback(cocos2d::Ref* pSender);
    
};

#endif /* ShopStore_hpp */
