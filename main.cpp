#include <QCoreApplication>
#include "Instance.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QObject::connect(&a, &QObject::destroyed, [] { qDebug()<< "\nDestruction de a"; });

     Instance  o1("Objet 1",&a);
     Instance  o2("objet 2",&o1);
     Instance  o3("objet 3",&o1);
     Instance  o4("objet 4",&o1);

     QObject::connect(&o1, &QObject::destroyed, [] { qDebug()<< "\nDestruction de o1"; });
     QObject::connect(&o2, &QObject::destroyed, [] { qDebug()<< "\nDestruction de o2"; });
     QObject::connect(&o3, &QObject::destroyed, [] { qDebug()<< "\nDestruction de o3"; });
     QObject::connect(&o4, &QObject::destroyed, [] { qDebug()<< "\nDestruction de o4"; });

     return 0; //a.exec(); est une boucle qui masque la destruction de l'objet
}
