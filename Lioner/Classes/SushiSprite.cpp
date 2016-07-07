#include "SushiSprite.h"

USING_NS_CC;

#define TOTAL_SUSHI (6)

static const char *sushiNormal[TOTAL_SUSHI] = {
	"circle_1n.png",
	"circle_2n.png",
	"circle_3n.png",
	"circle_4n.png",
	"circle_5n.png",
    "circle_6n.png"
};

static const char *sushiVertical[TOTAL_SUSHI] = {
	"circle_1v.png",
	"circle_2v.png",
	"circle_3v.png",
	"circle_4v.png",
	"circle_5v.png",
    "circle_6v.png"
};

static const char *sushiRight[TOTAL_SUSHI] = {
	"circle_1r.png",
	"circle_2r.png",
	"circle_3r.png",
	"circle_4r.png",
	"circle_5r.png",
    "circle_6r.png"
};

static const char *sushiLeft[TOTAL_SUSHI] = {
    "circle_1l.png",
    "circle_2l.png",
    "circle_3l.png",
    "circle_4l.png",
    "circle_5l.png",
    "circle_6l.png"
};




float SushiSprite::getContentWidth()
{
    static float itemWidth = 0;
    if (0 == itemWidth) {
        Sprite *sprite = Sprite::createWithSpriteFrameName(sushiNormal[0]);
        itemWidth = sprite->getContentSize().width;
    }
    return itemWidth;
}

SushiSprite::SushiSprite()
: m_col(0)
, m_row(0)
, m_imgIndex(0)
, m_isNeedRemove(false)
, m_ignoreCheck(false)
, m_displayMode(DISPLAY_MODE_NORMAL)
{
}

SushiSprite *SushiSprite::create(int row, int col)
{
	SushiSprite *sushi = new SushiSprite();
	sushi->m_row = row;
	sushi->m_col = col;
    sushi->m_imgIndex = arc4random() % TOTAL_SUSHI ;
    sushi->initWithSpriteFrameName(sushiNormal[sushi->m_imgIndex]);
	sushi->autorelease();
	return sushi;
}

void SushiSprite::setDisplayMode(DisplayMode mode)
{
    m_displayMode = mode;
    
    SpriteFrame *frame;
    switch (mode) {
        case DISPLAY_MODE_VERTICAL:
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(sushiVertical[m_imgIndex]);
            break;
        case DISPLAY_MODE_RIGHT:
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(sushiRight[m_imgIndex]);
            break;
        case DISPLAY_MODE_LEFT:
            frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(sushiLeft[m_imgIndex]);
            break;
        default:
            return;
    }
    setDisplayFrame(frame);
}
















