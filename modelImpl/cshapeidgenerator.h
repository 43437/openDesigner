#ifndef CSHAPEIDGENERATOR_H
#define CSHAPEIDGENERATOR_H

#include "model.h"

class CShapeIdGenerator : public IDGenerator
{
private:
    enum
    {
        eUnused = 0,
        eUsed = 1,
        eMIN_SHAPE_ID = 0,
        eMAX_SHAPE_ID = 1024,
    };
    static CShapeIdGenerator instance;
    static long iPos;
    char m_cIds[eMAX_SHAPE_ID];
    CShapeIdGenerator();
    ~CShapeIdGenerator();
    CShapeIdGenerator(const CShapeIdGenerator&){}
    CShapeIdGenerator& operator =(const CShapeIdGenerator&){}
public:
    static CShapeIdGenerator& getInstance(){return instance;}
    long genId();
    void delId(long id);
};

#endif // CSHAPEIDGENERATOR_H
