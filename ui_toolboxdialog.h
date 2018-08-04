/********************************************************************************
** Form generated from reading UI file 'toolboxdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBOXDIALOG_H
#define UI_TOOLBOXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ToolBoxDialog
{
public:
    QPushButton *ID_BTN_CURSOR;
    QPushButton *ID_BTN_DRAW;
    QPushButton *ID_BTN_SELECT;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *ID_BTN_MOVE;

    void setupUi(QDialog *ToolBoxDialog)
    {
        if (ToolBoxDialog->objectName().isEmpty())
            ToolBoxDialog->setObjectName(QStringLiteral("ToolBoxDialog"));
        ToolBoxDialog->setWindowModality(Qt::NonModal);
        ToolBoxDialog->resize(400, 32);
        ToolBoxDialog->setCursor(QCursor(Qt::ArrowCursor));
        ID_BTN_CURSOR = new QPushButton(ToolBoxDialog);
        ID_BTN_CURSOR->setObjectName(QStringLiteral("ID_BTN_CURSOR"));
        ID_BTN_CURSOR->setGeometry(QRect(10, 1, 31, 30));
        ID_BTN_CURSOR->setMouseTracking(false);
        QIcon icon;
        icon.addFile(QStringLiteral("res/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        ID_BTN_CURSOR->setIcon(icon);
        ID_BTN_CURSOR->setCheckable(true);
        ID_BTN_CURSOR->setChecked(true);
        ID_BTN_CURSOR->setAutoExclusive(true);
        ID_BTN_DRAW = new QPushButton(ToolBoxDialog);
        ID_BTN_DRAW->setObjectName(QStringLiteral("ID_BTN_DRAW"));
        ID_BTN_DRAW->setGeometry(QRect(40, 1, 31, 30));
        ID_BTN_DRAW->setMouseTracking(false);
        QIcon icon1;
        icon1.addFile(QStringLiteral("res/pen.png"), QSize(), QIcon::Normal, QIcon::Off);
        ID_BTN_DRAW->setIcon(icon1);
        ID_BTN_DRAW->setCheckable(true);
        ID_BTN_DRAW->setAutoExclusive(true);
        ID_BTN_SELECT = new QPushButton(ToolBoxDialog);
        ID_BTN_SELECT->setObjectName(QStringLiteral("ID_BTN_SELECT"));
        ID_BTN_SELECT->setGeometry(QRect(70, 1, 31, 30));
        ID_BTN_SELECT->setMouseTracking(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral("res/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        ID_BTN_SELECT->setIcon(icon2);
        ID_BTN_SELECT->setCheckable(true);
        ID_BTN_SELECT->setAutoExclusive(true);
        lineEdit = new QLineEdit(ToolBoxDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 31, 401, 2));
        lineEdit_2 = new QLineEdit(ToolBoxDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(0, 0, 401, 2));
        lineEdit_3 = new QLineEdit(ToolBoxDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(397, 1, 2, 30));
        lineEdit_4 = new QLineEdit(ToolBoxDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(0, 1, 2, 30));
        ID_BTN_MOVE = new QPushButton(ToolBoxDialog);
        ID_BTN_MOVE->setObjectName(QStringLiteral("ID_BTN_MOVE"));
        ID_BTN_MOVE->setGeometry(QRect(100, 1, 31, 30));
        ID_BTN_MOVE->setMouseTracking(false);
        QIcon icon3;
        icon3.addFile(QStringLiteral("res/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        ID_BTN_MOVE->setIcon(icon3);
        ID_BTN_MOVE->setCheckable(true);
        ID_BTN_MOVE->setAutoExclusive(true);

        retranslateUi(ToolBoxDialog);

        QMetaObject::connectSlotsByName(ToolBoxDialog);
    } // setupUi

    void retranslateUi(QDialog *ToolBoxDialog)
    {
        ID_BTN_CURSOR->setText(QString());
        ID_BTN_DRAW->setText(QString());
        ID_BTN_SELECT->setText(QString());
        ID_BTN_MOVE->setText(QString());
        Q_UNUSED(ToolBoxDialog);
    } // retranslateUi

};

namespace Ui {
    class ToolBoxDialog: public Ui_ToolBoxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBOXDIALOG_H
