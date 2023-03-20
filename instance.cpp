#include "instance.h"

Instance::Instance(QString var, QObject *parents)
    : QObject{parents}, var(var)
{
    qDebug() << "Instanciation de mon objet : " << var;
    qDebug() << "Son parent : " << parent();

    if(parent() && QString::fromLatin1(parent()->metaObject()->className())== "Instance"){
        qDebug() << "Nom du parent : " << qobject_cast<Instance *>(parent())->var;
        qDebug() << "Enfant du parent : " << parent()->children();
    }
    qDebug() <<Qt::endl;
}


Instance::~Instance(){
    qDebug() <<Qt::endl;
    qDebug() << "Destruction de l'objet" << var;
    qDebug() <<Qt::endl;

    if(parent() && QString::fromLatin1(parent()->metaObject()->className())== "Instance"){
        qDebug() << " Parent de linstance : " << qobject_cast<Instance *>(parent())->var;
        qDebug() << " Enfant de l'instance : " << children();

        foreach(QObject *child, children()){
           qDebug() << "   "<<qobject_cast<Instance *>(child)->var;
        }
        qDebug() << " Enfant du parent : " << qobject_cast<Instance *>(parent())->children();

    }else{
        qDebug() << "   Parent de l'instance : " << parent();
        qDebug() << "   Enfants de l'instance : " << children();
    }
}
