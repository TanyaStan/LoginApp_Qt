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
   QRegExp re(".*[*.!@#$%^&.*");
  // QRegExp rx("[\!@#$%^&*()-+]");

   bool hasUpperCase = false;
   bool hasLowerCase = false;
   bool hasDigit = false;
   bool hasSpecialCharacter = false;
   if(password.length()< 8){
       for (int i = 0; i < password.length(); i++) {
           if (password[i].isLower())
               hasLowerCase = true;
           if (password[i].isUpper())
               hasUpperCase = true;
           if (password[i].isDigit())
               hasDigit = true;
       }
   }
   if(re.indexIn(password) < 0){
     hasSpecialCharacter = true;

   }

//
    if(username =="test" && hasSpecialCharacter && hasLowerCase && hasDigit && hasUpperCase ){
        //qDebug() << "This is the password: "<<hasSpecialCharacter;
         QMessageBox::information(this,"Login","Login successful");
       // QMessageBox::information(this,"Login","Login successful");
    }
    else{
        QMessageBox::warning(this,"Login","Login unsuccesful");
    }


}

