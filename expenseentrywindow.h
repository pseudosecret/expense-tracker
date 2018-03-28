#ifndef EXPENSEENTRYWINDOW_H
#define EXPENSEENTRYWINDOW_H

#include <QMainWindow>

namespace Ui {
class ExpenseEntryWindow;
}

class ExpenseEntryWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExpenseEntryWindow(QWidget *parent = 0);
    ~ExpenseEntryWindow();

private slots:
    void on_actionNewDatabaseFile_triggered();

    void on_actionOpenDatabase_triggered();

    void on_actionExit_triggered();

    void on_actionSave_Database_triggered();

private:
    Ui::ExpenseEntryWindow *ui;
};

#endif // EXPENSEENTRYWINDOW_H
