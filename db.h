#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QString>

class db
{
private:
    QSqlDatabase database;




public:
    db();
    void openDBConnection(QString fileName);
    void closeDBConnection();
    void createDatabase();






};

#endif // DB_H
