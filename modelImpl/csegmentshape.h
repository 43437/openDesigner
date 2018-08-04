#ifndef CSEGMENTSHAPE_H
#define CSEGMENTSHAPE_H

#include "model.h"

class CSegmentShape : public CShape
{
public:
    CSegmentShape();
    ~CSegmentShape();
    void render(QPainter& panter);
};

#endif // CSEGMENTSHAPE_H
