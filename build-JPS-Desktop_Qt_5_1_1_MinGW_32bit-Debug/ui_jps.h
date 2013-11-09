/********************************************************************************
** Form generated from reading UI file 'jps.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JPS_H
#define UI_JPS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JPS
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_6;
    QLabel *label_4;
    QPushButton *pushButton_8;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QComboBox *comboBox;

    void setupUi(QWidget *JPS)
    {
        if (JPS->objectName().isEmpty())
            JPS->setObjectName(QStringLiteral("JPS"));
        JPS->resize(983, 598);
        groupBox = new QGroupBox(JPS);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 400, 321, 141));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 40, 75, 23));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 80, 46, 13));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 46, 13));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(210, 100, 75, 23));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(30, 40, 171, 20));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(30, 100, 171, 20));
        groupBox_2 = new QGroupBox(JPS);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 321, 381));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 70, 46, 13));
        lineEdit_3 = new QLineEdit(groupBox_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 40, 261, 20));
        pushButton_6 = new QPushButton(groupBox_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setEnabled(false);
        pushButton_6->setGeometry(QRect(20, 190, 75, 31));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 20, 46, 13));
        pushButton_8 = new QPushButton(groupBox_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(220, 190, 75, 31));
        pushButton_4 = new QPushButton(groupBox_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(220, 250, 75, 41));
        lineEdit_4 = new QLineEdit(groupBox_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 90, 261, 20));
        pushButton_7 = new QPushButton(groupBox_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(120, 190, 75, 31));
        pushButton_9 = new QPushButton(groupBox_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(120, 250, 75, 41));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 46, 13));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 310, 75, 51));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(14, 118, 23);"));
        pushButton_5 = new QPushButton(groupBox_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(120, 310, 75, 51));
        pushButton_5->setStyleSheet(QStringLiteral("color: rgb(255, 103, 76);"));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 150, 171, 22));

        retranslateUi(JPS);

        QMetaObject::connectSlotsByName(JPS);
    } // setupUi

    void retranslateUi(QWidget *JPS)
    {
        JPS->setWindowTitle(QApplication::translate("JPS", "JPS", 0));
        groupBox->setTitle(QApplication::translate("JPS", "Save/Load file", 0));
        pushButton_2->setText(QApplication::translate("JPS", "Load Map", 0));
        label_3->setText(QApplication::translate("JPS", "Result file", 0));
        label->setText(QApplication::translate("JPS", "Map file", 0));
        pushButton_3->setText(QApplication::translate("JPS", "Save Map", 0));
        lineEdit->setText(QApplication::translate("JPS", "space1.txt", 0));
        lineEdit_2->setText(QApplication::translate("JPS", "route.txt", 0));
        groupBox_2->setTitle(QApplication::translate("JPS", "Draw", 0));
        label_5->setText(QApplication::translate("JPS", "Height", 0));
        lineEdit_3->setText(QApplication::translate("JPS", "30", 0));
        pushButton_6->setText(QApplication::translate("JPS", "BLOCK", 0));
        label_4->setText(QApplication::translate("JPS", "Width", 0));
        pushButton_8->setText(QApplication::translate("JPS", "FINISH", 0));
        pushButton_4->setText(QApplication::translate("JPS", "Redraw map", 0));
        lineEdit_4->setText(QApplication::translate("JPS", "30", 0));
        pushButton_7->setText(QApplication::translate("JPS", "START", 0));
        pushButton_9->setText(QApplication::translate("JPS", "Clear blocks", 0));
        label_2->setText(QApplication::translate("JPS", "Map type", 0));
        pushButton->setText(QApplication::translate("JPS", "Find path", 0));
        pushButton_5->setText(QApplication::translate("JPS", "Clear path", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("JPS", "planar", 0)
         << QApplication::translate("JPS", "cylinder", 0)
         << QApplication::translate("JPS", "tor", 0)
        );
        comboBox->setCurrentText(QApplication::translate("JPS", "planar", 0));
    } // retranslateUi

};

namespace Ui {
    class JPS: public Ui_JPS {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JPS_H
