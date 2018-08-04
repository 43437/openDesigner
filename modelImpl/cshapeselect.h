#ifndef CSHAPESELECT_H
#define CSHAPESELECT_H

#include "model.h"

class CShapeSelect : public CShape
{
public:
    CShapeSelect();
    ~CShapeSelect();
    void render(QPainter &painter);
};

#endif // CSHAPESELECT_H
