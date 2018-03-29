#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QSqlDatabase>
#include <QString>

class DbManager
{
    private:
        QSqlDatabase database;
    public:
        DbManager(const QString& path);
        void closeDBConnection();
        bool createDatabase();
        bool insertIntoDatabase(const QString qsName,
                                    const QString qsDescription,
                                    const QString qsCategory,
                                    const QString qsDateOfPurchase,
                                    const QString qsCost);

};

#endif // DB_H

