#include "cshapefactory.h"

CShapeFactory::CShapeFactory(QObject *parent) : QObject(parent)
{

}

CShape* CShapeFactory::genShape(const DATADEFINEPUB::ESHAPETYPE &eShapeType)
{
    switch(eShapeType)
    {
    case DATADEFINEPUB::eShapeSegment:
        return new CSegmentShape();
        break;
    case DATADEFINEPUB::eShapeSelect:
        return new CShapeSelect();
        break;
    case DATADEFINEPUB::eShapeBase:
        return new CShapeBase();
        break;
    case DATADEFINEPUB::eDistance:
        return new CDistance();
        break;
    default:
        break;
    }
}

CShape* CShapeFactory::genShape(const DATADEFINEPUB::ETOOLBTN &eMode)
{
    switch(eMode)
    {
    case DATADEFINEPUB::eToolBtnDraw:
        return new CSegmentShape();
        break;
    case DATADEFINEPUB::eToolBtnSelect:
        return new CShapeSelect();
        break;
    }
}
