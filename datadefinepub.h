#ifndef DATADEFINEPUB_H
#define DATADEFINEPUB_H

namespace DATADEFINEPUB {

    enum CONSTANT
    {

    };

    typedef enum
    {
        eShapeBase,
        eShapeSegment,
        eShapeSelect,
        eDistance,
    }ESHAPETYPE;

    typedef enum
    {
        eToolBtnNone,
        eToolBtnCursor,
        eToolBtnDraw,
        eToolBtnSelect,
        eToolBtnMove,
    }ETOOLBTN;
}

#endif // DATADEFINEPUB_H
