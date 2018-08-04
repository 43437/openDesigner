#include "cshapeselect.h"

CShapeSelect::CShapeSelect()
{

}

CShapeSelect::~CShapeSelect()
{

}

void CShapeSelect::render(QPainter &painter)
{
    painter.setPen(Qt::DashDotLine);
    painter.drawRect(m_rect);
}
