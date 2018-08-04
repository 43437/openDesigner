#ifndef CSHAPE_H
#define CSHAPE_H

#include <QObject>
#include <QRect>
#include <QPoint>
#include <QPainter>

class CShape : public QObject
{
    Q_OBJECT
public:
    explicit CShape(QObject *parent = 0);
    virtual ~CShape() = 0;
    virtual QRect& getRect(){return m_rect;}
    virtual void setRect(const QRect& rect){this->m_rect = rect;}
    virtual void setIsSelected(bool isSelected){this->m_isSelected = isSelected;}
    virtual bool getIsSelected(){return this->m_isSelected;}
    virtual void updatePos(int moveX, int moveY);
    virtual bool setSelected(const QPoint& point);
    virtual bool setSelected(const QRect& rect);
    virtual bool isConflict(const QRect& rect);
    virtual bool isConflict(CShape& shape);
    virtual void render(QPainter &painter);

protected:
    QRect m_rect;
    bool m_isSelected;

signals:

public slots:
};

#endif // CSHAPE_H
