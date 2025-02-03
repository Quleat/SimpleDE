#include "jsonutilities.h"
#include <QFile>
#include <QJsonArray>
#include <QDebug>
#include <QJsonDocument>

JsonUtilities::JsonUtilities(QString path)
{
    QStringList strings;
    QFile file(path);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        QJsonArray jsonArray = jsonDoc.array();
        for(auto value : jsonArray){
            strings.append(value.toString());
        }
        file.close();
    }
    if(strings.count() < 2){
        qDebug() << "Couldn't load the Json config";
    }
    else{
        dbPath = strings.at(0);
        int colCount = strings.count();
        columns = strings.mid(1, colCount / 2);
        dataTypes = strings.mid(colCount / 2);
    }
}

QString JsonUtilities::getDBPath(){
    return dbPath;
}
QStringList JsonUtilities::getColumns(){
    return columns;
}

QStringList JsonUtilities::getTypes()
{
    return dataTypes;
}

void JsonUtilities::saveJson(QString path, QStringList list){
    QJsonArray jsonArray;
    for (const QString &str : list) {
        jsonArray.append(str);
    }

    QJsonDocument jsonDoc(jsonArray);
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDoc.toJson());
        file.close();
    }
}


