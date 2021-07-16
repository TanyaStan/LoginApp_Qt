#include <QCoreApplication>
#include <QDebug>
#include <QRegularExpression>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString password = "HelloWorld";

    QRegExp re("[^A-Za-z0-9]");
    if (re.indexIn(password) < 0)
       qDebug() << "No special chars";
    else
       qDebug() << "Found at least one special char";

    password = "$Abc";
    if (re.indexIn(password) < 0)
       qDebug() << "No special chars";
    else
       qDebug() << "Found at least one special char";
    return a.exec();
}
