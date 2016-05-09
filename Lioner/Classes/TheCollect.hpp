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
USING_NS_CC;
class TheCollect : public cocos2d::Layer
{
public:
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // implement the "static node()" method manually
    CREATE_FUNC(TheCollect);
    void backmenuItemCallback(cocos2d::Ref* pSender);
};

#endif /* TheCollect_hpp */
