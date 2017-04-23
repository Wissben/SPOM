#ifndef SELECTOR_H
#define SELECTOR_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include "opencv2/opencv.hpp"

namespace Ui {
class Selector;
}

class Selector : public QWidget
{
    Q_OBJECT

public:
    explicit Selector(QWidget *parent = 0);
    ~Selector();


private slots:
    void on_radioButton_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_gradiantOublieux_toggled(bool checked);

    void on_moyenneRecurssive_toggled(bool checked);

    void on_moyenneArith_toggled(bool checked);

    void on_moyenneSD_toggled(bool checked);

    void on_SAP_toggled(bool checked);

    void on_Selector_destroyed();

    void on_quitSelector_clicked();

    void on_gradiantOublieux_clicked();


public :
    Ui::Selector *ui;
};

#endif // SELECTOR_H
