//
//  SendCardlayer.hpp
//  Lioner
//
//  Created by 张伟 on 16/5/23.
//
//

#ifndef SendCardlayer_hpp
#define SendCardlayer_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class SendCardlayer:public Layer
{
public:
    SendCardlayer();
    ~SendCardlayer();
    
    virtual bool init();
    CREATE_FUNC(SendCardlayer)
    
protected:
    void runSendAmt(Ref * obj);
    
private:
    Size m_winSize;
    Vector<cocos2d::Sprite *> m_cardVec;
    Vector<cocos2d::Sprite *> m_cardBg;

};

#endif /* SendCardlayer_hpp */
