#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <regex>

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

void MainWindow::on_pushButton_login_clicked()
{
   QString username = ui->lineEdit_username->text();
   QString password = ui->lineEdit_password->text();
   QRegExp rx("\\!@#$%^&*()-+");
   QString abc = "$abc";

   bool hasUpperCase = false;
   bool hasLowerCase = false;
   bool hasDigit = false;
   bool hasSpecialCharacter = false;

   for (int i = 0; i < password.length(); i++) {
       if (password[i].isLower())
           hasLowerCase = true;
       if (password[i].isUpper())
           hasUpperCase = true;
       if (password[i].isDigit())
           hasDigit = true;
       if(rx.indexIn(password, i)){
           hasSpecialCharacter = true;
       }
   }
   //&& hasLowerCase && hasDigit && hasUpperCase

    if(username =="test" && hasSpecialCharacter){
         QMessageBox::information(this,"Login","Login successful");
       // QMessageBox::information(this,"Login","Login successful");
    }
    else{
        QMessageBox::warning(this,"Login","Login unsuccesful");
    }


}

