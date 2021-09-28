#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionreverse_strEdtLower_triggered()
{
    QString sLower;
    ui->statusBar->showMessage("statusBar: reverse_strEdtLower");

    sLower=ui->lineEditLower->text();
    int LowerLength=sLower.length();
    int HalfLowerLength=LowerLength/2; //делим с остатком
    int i;
    QChar chTemp='r';
    for(i=0;i<HalfLowerLength; i++)
    {
        chTemp=sLower[i];
     //   sLower[i]="r";
        sLower.replace(i, 1, sLower[LowerLength-1-i]);
        sLower.replace(LowerLength-1-i, 1, chTemp);
    }
    ui->lineEditLower->setText(sLower);
}

void MainWindow::on_actionreverse_strEdtUpper_triggered()
{
    QString sUpper;
    ui->statusBar->showMessage("statusBar: reverse_strEdtUpper");

    sUpper=ui->lineEditUpper->text();
    int UpperLength=sUpper.length();
    int HalfUpperLength=UpperLength/2; //делим с остатком
    int i;
    QChar chTemp='r';
    for(i=0;i<HalfUpperLength; i++)
    {
        chTemp=sUpper[i];
     //   sLower[i]="r";
        sUpper.replace(i, 1, sUpper[UpperLength-1-i]);
        sUpper.replace(UpperLength-1-i, 1, chTemp);
    }
    ui->lineEditUpper->setText(sUpper);
}

void MainWindow::on_actionreverseAll_triggered()
{
    on_actionreverse_strEdtLower_triggered();
    on_actionreverse_strEdtUpper_triggered();
    ui->statusBar->showMessage("statusBar: reverseAll");
}

void MainWindow::on_actionswap_strEdtLower_strEdtUpper_triggered()
{
    ui->statusBar->showMessage("statusBar: swap(strEdtLower, strEdtUpper)");
    QString strTemp=ui->lineEditLower->text();
    ui->lineEditLower->setText(ui->lineEditUpper->text());
    ui->lineEditUpper->setText(strTemp);
}

void MainWindow::on_actionconcat_strEdtLower_strEdtUpper_triggered()
{
    ui->statusBar->showMessage("statusBar: concat(strEdtLower, strEdtUpper)");
    ui->lineEditLower->setText(ui->lineEditLower->text()+ui->lineEditUpper->text());
}

void MainWindow::on_actionconcat_strEdtUpper_strEdtLower_triggered()
{
    ui->statusBar->showMessage("statusBar: concat(strEdtUpper, strEdtLower)");
    ui->lineEditUpper->setText(ui->lineEditUpper->text()+ui->lineEditLower->text());
}
