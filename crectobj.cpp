#include "crectobj.h"

CRectObj::CRectObj(QObject *parent) : QObject(parent),
    m_rect(0, 0, 0, 0),
    m_bChanged(true),
    m_bIsSelected(false)
{

}

bool CRectObj::isConflict(const QRect &rect)
{
    QRect crossRect = this->getRect() & rect;
    if(crossRect.isEmpty())
    {
        return false;
    }else
    {
        return true;
    }
}

QRect CRectObj::getRect()
{
    if(m_bChanged)
    {
        m_rect = QRect(this->m_TopLeft, this->m_BottomRight);
    }
    return m_rect;
}
