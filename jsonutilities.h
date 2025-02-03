#ifndef JSONUTILITIES_H
#define JSONUTILITIES_H
#include <QString>
#include <QFile>

class JsonUtilities
{
    QString dbPath;
    QStringList columns;
    QStringList dataTypes;
public:
    JsonUtilities(QString path);
    QString getDBPath();
    QStringList getColumns();
    QStringList getTypes();

    void saveJson(QString path, QStringList list);
};

#endif // JSONUTILITIES_H
