#include "dbmanager.h"
#include <QSql>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
using namespace std;

DbManager::DbManager(const QString& path) {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(path);
    if(!database.open()) {
        qDebug() << "Error: could not connect to database!";
    } else {
        qDebug() << "Connect to " + path + " made!";
    }
}

void DbManager::closeDBConnection() {
    database.close();
}

bool DbManager::createDatabase() {
    bool success = false;
    QSqlQuery query;
    query.prepare("CREATE TABLE purchases "
                  "(id INTEGER PRIMARY KEY "
                  ", name VARCHAR(30) "
                  ", description VARCHAR(250) "
                  ", category VARCHAR(20) "
                  ", dateOfPurchase DATE "
                  ", cost INT);");
    if(query.exec()) {
        success = true;
    } else {
        qDebug() << "Create table error: "
                 << query.lastError();
    }
    return success;
}

bool DbManager::insertIntoDatabase(const QString qsName,
                            const QString qsDescription,
                            const QString qsCategory,
                            const QString qsDateOfPurchase,
                            const QString qsCost) {
    bool success = false;
    int cost = qsCost.toInt();
    cost *= 100;
    QSqlQuery query;
    query.prepare("INSERT INTO purchases "
               "(name, description, category, dateOfPurchase, cost) "
               "VALUES (:name, :description, :category, :dateOfPurchase, :cost);");
    query.bindValue(":name", qsName);
    query.bindValue(":description", qsDescription);
    query.bindValue(":category", qsCategory);
    query.bindValue(":dateOfPurchase", qsDateOfPurchase);
    query.bindValue(":cost", cost);
    if(query.exec()) {
        success = true;
    } else {
        qDebug() << "Insert purchase error: "
               << query.lastError();
    }
    return success;
}

