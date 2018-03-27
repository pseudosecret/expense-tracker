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

private:
    Ui::ExpenseEntryWindow *ui;
};

#endif // EXPENSEENTRYWINDOW_H
