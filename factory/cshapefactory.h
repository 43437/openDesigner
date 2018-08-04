#ifndef CSHAPEFACTORY_H
#define CSHAPEFACTORY_H

#include <QObject>
#include "model.h"
#include "datadefinepub.h"

class CShapeFactory : public QObject
{
private:
    Q_OBJECT

public:
    explicit CShapeFactory(QObject *parent = 0);
    static CShape* genShape(const DATADEFINEPUB::ESHAPETYPE& eShapeType);
    static CShape* genShape(const DATADEFINEPUB::ETOOLBTN& eMode);

signals:

public slots:
};

#endif // CSHAPEFACTORY_H
