#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pButton = new QPushButton("Insert", this);
    m_pButton->move(50, 50);
    //connect(m_pButton, SIGNAL(clicked(bool)), this, SLOT(InsertButton()));
    _InitDataBase();
    InsertToDatabase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InsertButton()
{
    InsertToDatabase();
}

void MainWindow::InsertToDatabase()
{

    if (connect(QCoreApplication::applicationDirPath() + "demo.db"))
    {
        QSqlQuery qSqlQuery;

        qSqlQuery.prepare("INSERT INTO student (DonorFirstName, DonorLastName, TestTime, BirthDate, DonorID, TestSite, Operator, "
                          "PreEmployment, Random, ReasonSuspicionCause, PostAccident, ReturnToDuty, FollowUp, Comments, "
                          "TemperatureNormal, ProductDefinition, ExpirationDate, ProductLot, ProductID, ProgramsNumber) "
                          "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");

        //qSqlQuery.addBindValue(1001);
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");//
        //
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        //
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue("names");
        qSqlQuery.addBindValue(44);


        if (!qSqlQuery.exec())
        {
            qDebug() << qSqlQuery.lastError();
            QMessageBox::critical(0, QObject::tr("Database Error"),
                                  qSqlQuery.lastError().text());
        }
        qSqlQuery.finish();
        qSqlQuery.exec("SELECT id, DonorFirstName FROM student");
        while (qSqlQuery.next()) {
            int name = qSqlQuery.value(0).toInt();
            QString age = qSqlQuery.value(1).toString();
            qDebug() << name << ": " << age;
        }

    }
}

void MainWindow::_InitDataBase()
{
    if (connect(QCoreApplication::applicationDirPath() + "demo.db")) {
           QSqlQuery query;
           if (!query.exec("CREATE TABLE student ("
                           "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                           "DonorFirstName VARCHAR,"
                           "DonorLastName VARCHAR,"
                           "TestTime VARCHAR,"
                           "BirthDate VARCHAR,"
                           "DonorID VARCHAR,"
                           "TestSite VARCHAR,"
                           "Operator VARCHAR,"
                          "PreEmployment VARCHAR,"
                           "Random VARCHAR,"
                           "ReasonSuspicionCause VARCHAR,"
                           "PostAccident VARCHAR,"
                           "ReturnToDuty VARCHAR,"
                           "FollowUp VARCHAR,"
                           "Comments VARCHAR,"
                           "TemperatureNormal VARCHAR,"
                           "ProductDefinition VARCHAR,"
                           "ExpirationDate VARCHAR,"
                           "ProductLot VARCHAR,"
                           "ProductID VARCHAR,"
                           "ProgramsNumber INT)"))
           {
               QMessageBox::critical(0, QObject::tr("Database Error"),
                                     query.lastError().text());
           }
       }



}

bool MainWindow::connect(const QString &dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setHostName("host");
//    db.setDatabaseName("dbname");
//    db.setUserName("username");
//    db.setPassword("password");
    db.setDatabaseName(dbName);
    if (!db.open()) {
        QMessageBox::critical(0, QObject::tr("Database Error"),
                              db.lastError().text());
        return false;
    }
    return true;
}
