#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "QtWidgets/qwidget.h"
#include "qtmetamacros.h"
#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

    class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:

    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_Rand_clicked();
};

#endif // MAINWINDOW_H
