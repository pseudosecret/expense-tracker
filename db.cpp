#include "db.h"
#include <QSql>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
using namespace std;

class Db {
    QSqlDatabase database;
    public:
        void openDBConnection(QString fileName);
        void closeDBConnection();
        void createDatabase();
};

void Db::openDBConnection(QString fileName) {
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(fileName);
    database.open();
}

void Db::closeDBConnection() {
    database.close();
}

void Db::createDatabase() {
    QSqlQuery query;
    query.exec("CREATE TABLE test "
               "(id INTEGER PRIMARY KEY, "
               "field VARCHAR(20))");
}
