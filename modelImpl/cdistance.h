#ifndef CDISTANCE_H
#define CDISTANCE_H

#include "model.h"
#include "datadefinepub.h"

class CDistance : public CShape
{
private:
    QRect& getRect(){return m_rect;}
    void setRect(const QRect& rect){this->m_rect = rect;}
    void setIsSelected(bool isSelected){this->m_isSelected = isSelected;}
    bool getIsSelected(){return this->m_isSelected;}
    bool setSelected(const QPoint& point){point;}
    bool setSelected(const QRect& rect){rect;}
    bool isConflict(const QRect& rect){rect;}
    bool isConflict(CShape& shape){shape;}
    void render(QPainter &painter){painter;}
    void updatePos(int posX, int posY){posX, posY;}
public:
    CDistance();
    void updatePos(QPoint beginPos, QPoint endPos);
    void updatePos(QPoint endPos);
    QPair<int, int> getDistance();
    ~CDistance();

private:
    QPair<QPoint, QPoint> m_pos;
};

#endif // CDISTANCE_H
