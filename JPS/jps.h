#ifndef JPS_H
#define JPS_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include "robot.h"
#include "map.h"

namespace Ui {
class JPS;
}

class JPS : public QWidget
{
    Q_OBJECT
    QPainter * fPainter;
    Map * space;
    int type_draw;
public:
    explicit JPS(QWidget *parent = 0);
    ~JPS();

private slots:
    void errorMessage(const std::string &m);

    void on_pushButton_clicked();

    void paintEvent(QPaintEvent * event);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void mousePressEvent(QMouseEvent * e);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::JPS *ui;
};

#endif // JPS_H
