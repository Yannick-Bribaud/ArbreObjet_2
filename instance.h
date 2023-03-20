#ifndef INSTANCE_H
#define INSTANCE_H

#include <QObject>
#include <QDebug>
#include <QString>

class Instance : public QObject
{
    Q_OBJECT
public:
    explicit Instance(QString var, QObject *parents = nullptr);
    ~Instance();


protected:
    QString var;

};

#endif // INSTANCE_H
