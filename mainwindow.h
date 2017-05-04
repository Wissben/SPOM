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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_spinBox_editingFinished();

    void on_alphaChooser_editingFinished();

    void on_alphaChooser_valueChanged(int arg1);

public slots:
    void processFrameAndUpdateGUI();

private:
    Ui::MainWindow *ui;
    Selector selector;
    cv::VideoCapture capWebcam;
    cv::Mat matWebcam;
    QImage qimgWebcam;
    QTimer* tmrTimer;

};

#endif // MAINWINDOW_H
