#include "cdistance.h"

CDistance::CDistance()
{

}

CDistance::~CDistance()
{

}

void CDistance::updatePos(QPoint beginPos, QPoint endPos)
{
    this->m_pos = QPair<QPoint, QPoint>(beginPos, endPos);
}

void CDistance::updatePos(QPoint endPos)
{
    this->m_pos.second = endPos;
}

QPair<int, int> CDistance::getDistance()
{
    return QPair<int, int>(this->m_pos.second.x() - this->m_pos.first.x(), this->m_pos.second.y() - this->m_pos.first.y());
}
