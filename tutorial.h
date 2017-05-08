#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QWidget>
#include <vector>
#include <QLabel>

namespace Ui {
class Tutorial;
}

class Tutorial : public QWidget
{
    Q_OBJECT

public:
    explicit Tutorial(QWidget *parent = 0);
    ~Tutorial();

private:
    Ui::Tutorial *ui;
public:
    std::vector<QPixmap> frames;
    std::vector<QLabel*> labels;
    int index;
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // TUTORIAL_H
