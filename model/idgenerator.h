#ifndef IDGENERATOR_H
#define IDGENERATOR_H

#include <QObject>

class IDGenerator : public QObject
{
    Q_OBJECT
public:
    explicit IDGenerator(QObject *parent = 0);
    virtual long genId() = 0;
    virtual void delId(long id) = 0;
    virtual ~IDGenerator(){}
    IDGenerator(const IDGenerator&){}
    IDGenerator& operator=(const IDGenerator &){}

signals:

public slots:
};

#endif // IDGENERATOR_H
