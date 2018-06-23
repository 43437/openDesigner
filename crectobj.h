#ifndef CRECTOBJ_H
#define CRECTOBJ_H

#include <QObject>
#include <QRect>
#include <QPoint>

class CRectObj : public QObject
{
    Q_OBJECT
public:
    explicit CRectObj(QObject *parent = 0);

    void setTopLeft(const QPoint& point){this->m_TopLeft = point; m_bChanged = true;}
    void setBottomRight(const QPoint& point){this->m_BottomRight = point;  m_bChanged = true;}

    QRect getRect();
    bool isConflict(const QRect& rect);

signals:

public slots:

private:
    QRect m_rect;
    QPoint m_TopLeft, m_BottomRight;
    bool m_bChanged;
    bool m_bIsSelected;
};

#endif // CRECTOBJ_H
