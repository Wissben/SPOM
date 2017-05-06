#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "selector.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
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


    void on_pushButton_3_clicked();

public slots:


private:
    Ui::MainWindow *ui;
    Selector selector;
    cv::VideoCapture capWebcam;
    cv::Mat matWebcam;
    QImage qimgWebcam;
    QTimer* tmrTimer;

};

#endif // MAINWINDOW_H
