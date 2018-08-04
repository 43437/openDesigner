#include "cshape.h"

CShape::CShape(QObject *parent) : QObject(parent)
  ,m_isSelected(false)
  ,m_rect(0,0,0,0)
{

}

CShape::~CShape()
{

}

bool CShape::isConflict(const QRect &rect)
{
    QRect conflictRect = (this->m_rect & rect);
    return !conflictRect.isEmpty();
}

bool CShape::isConflict(CShape &shape)
{
    return this->isConflict(shape.getRect());
}

bool CShape::setSelected(const QPoint &point)
{
    return (m_isSelected = m_rect.contains(point));
}

bool CShape::setSelected(const QRect &rect)
{
    return (m_isSelected = isConflict(rect));
}

void CShape::render(QPainter &painter)
{
    painter.drawRect(this->getRect());
}

void CShape::updatePos(int moveX, int moveY)
{
    this->m_rect = QRect((m_rect.x() + moveX), (m_rect.y() + moveY), m_rect.width(), m_rect.height());
}
