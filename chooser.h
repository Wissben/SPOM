#ifndef CHOOSER_H
#define CHOOSER_H

#include <QWidget>

namespace Ui {
class Chooser;
}

class Chooser : public QWidget
{
    Q_OBJECT

public:
    explicit Chooser(QWidget *parent = 0);
    ~Chooser();

private slots:
    void on_gradiantMorph_clicked();

    void on_pushButton_clicked();

    void on_alphaChooserSAP_valueChanged(int value);

    void on_NChooser_valueChanged(int arg1);

    void on_alphaChooserRec_valueChanged(int value);

    void on_recChooser_clicked();

    void on_gradiantChooser_clicked();

    void on_alphaChooserGrad_valueChanged(int value);

public:
    Ui::Chooser *ui;
};

#endif // CHOOSER_H
