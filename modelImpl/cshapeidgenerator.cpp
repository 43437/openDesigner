#include "cshapeidgenerator.h"

CShapeIdGenerator CShapeIdGenerator::instance;
long CShapeIdGenerator::iPos = 0;

CShapeIdGenerator::CShapeIdGenerator()
{
    memset(m_cIds, eUnused, eMAX_SHAPE_ID);
}

CShapeIdGenerator::~CShapeIdGenerator()
{

}

long CShapeIdGenerator::genId()
{
    for(int i=0; i< eMAX_SHAPE_ID; i++)
    {
        if((++iPos) > (eMAX_SHAPE_ID - 1))
        {
            iPos = 0;
        }
        if( eUnused == m_cIds[iPos])
        {
            return iPos;
        }
    }
    return -1;
}

void CShapeIdGenerator::delId(long id)
{
    if( id >= eMIN_SHAPE_ID && id < eMAX_SHAPE_ID )
    {
        m_cIds[id] = eUnused;
    }
}
