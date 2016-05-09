//
//  SelectDrama.hpp
//  Lioner
//
//  Created by 张伟 on 16/3/28.
//
//

#ifndef SelectDrama_hpp
#define SelectDrama_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;

class SelectDrama: public Layer
{
public:
    static Scene* createscene();
    virtual bool init();
    void setstring(int sc);
    __String* strings;
    CREATE_FUNC(SelectDrama);
};



#endif /* SelectDrama_hpp */
