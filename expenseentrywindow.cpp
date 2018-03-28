#include "expenseentrywindow.h"
#include "ui_expenseentrywindow.h"
#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDataStream>
#include <QIODevice>
#include <QMessageBox>
#include <QFileDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

ExpenseEntryWindow::ExpenseEntryWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExpenseEntryWindow)
{
    ui->setupUi(this);
}

ExpenseEntryWindow::~ExpenseEntryWindow()
{
    delete ui;
}

void ExpenseEntryWindow::on_actionNewDatabaseFile_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Database File"), "",
        tr("SQLite3 (*.sqlite3);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                file.errorString());
            return;
        }
        QFileInfo fileInfo(file.fileName());
        QString theFileName(fileInfo.fileName());
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(theFileName);
        db.open();
        QSqlQuery query;
        query.exec("CREATE TABLE test "
                   "(id INTEGER PRIMARY KEY, "
                   "field VARCHAR(20))");
//        query.exec("INSERT INTO test "
//                   "(id, field) "
//                   "VALUES "
//                   "(1, 'it works!')");
    }
}

void ExpenseEntryWindow::on_actionOpenDatabase_triggered()
{

}

void ExpenseEntryWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}

void ExpenseEntryWindow::on_actionSave_Database_triggered()
{

}
