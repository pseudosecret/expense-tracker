#include "expenseentrywindow.h"
#include "ui_expenseentrywindow.h"

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
