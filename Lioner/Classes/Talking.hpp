//
//  Talking.hpp
//  Lioner
//
//  Created by 张伟 on 16/4/27.
//
//

#ifndef Talking_hpp
#define Talking_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <tinyxml2/tinyxml2.h>
USING_NS_CC;
using namespace tinyxml2;

class Talking:public Layer
{
public:
    Sprite* di;
    Label* labelcontent;
    Label* labelname;
    
    Sprite* role1;
    Sprite* role2;
    Sprite* jiantou;
    Sprite* dizuo;
    
    
    int n;
    std::string content;
    const char*  getContent(){return content.c_str();}
    bool role=true;
    
    XMLDocument* myDoucument;
    XMLElement* root;
    XMLElement* chd;
    XMLElement* element;
    XMLElement* elementpng;
    const XMLAttribute* attr;
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Talking);
    
    void copyFile(std::string filename);
    void readxml(std::string filename);
    void logic(float t);
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    void backmenuItemCallback(cocos2d::Ref* pSender);
    
    void setstring(int sc);
    __String* strings;
    char tmp[50];
    
};

#endif /* Talking_hpp */
