#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

public slots:
    void InsertButton();
public:
    // 将上方获取的数据插入数据库
    void InsertToDatabase();
    // 数据库
    void _InitDataBase();// 初始化数据库
    bool connect(const QString &dbName);

private:
    Ui::MainWindow *ui;
    QPushButton *m_pButton;
};

#endif // MAINWINDOW_H
