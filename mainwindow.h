#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "selector.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_editingFinished();

    void on_alphaChooser_editingFinished();

    void on_alphaChooser_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Selector selector;
};

#endif // MAINWINDOW_H
