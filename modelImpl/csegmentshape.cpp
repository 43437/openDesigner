#include "csegmentshape.h"

CSegmentShape::CSegmentShape()
{

}

CSegmentShape::~CSegmentShape()
{

}

void CSegmentShape::render(QPainter &painter)
{
    if(this->m_isSelected)
    {
        painter.setBrush(Qt::Dense6Pattern);
    }else
    {
        painter.setBrush(Qt::NoBrush);
    }
    painter.drawRect(m_rect);
}
