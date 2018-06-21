/********************************************************************************
** Form generated from reading UI file 'ctoolbox.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTOOLBOX_H
#define UI_CTOOLBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_CToolBox
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioBtnSelect;
    QRadioButton *radioBtnObject;
    QRadioButton *radioBtnLine;

    void setupUi(QDialog *CToolBox)
    {
        if (CToolBox->objectName().isEmpty())
            CToolBox->setObjectName(QStringLiteral("CToolBox"));
        CToolBox->resize(473, 36);
        groupBox = new QGroupBox(CToolBox);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 0, 191, 41));
        radioBtnSelect = new QRadioButton(groupBox);
        radioBtnSelect->setObjectName(QStringLiteral("radioBtnSelect"));
        radioBtnSelect->setGeometry(QRect(20, 20, 89, 16));
        radioBtnObject = new QRadioButton(groupBox);
        radioBtnObject->setObjectName(QStringLiteral("radioBtnObject"));
        radioBtnObject->setGeometry(QRect(80, 20, 89, 16));
        radioBtnLine = new QRadioButton(groupBox);
        radioBtnLine->setObjectName(QStringLiteral("radioBtnLine"));
        radioBtnLine->setGeometry(QRect(140, 20, 89, 16));

        retranslateUi(CToolBox);

        QMetaObject::connectSlotsByName(CToolBox);
    } // setupUi

    void retranslateUi(QDialog *CToolBox)
    {
        CToolBox->setWindowTitle(QApplication::translate("CToolBox", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        radioBtnSelect->setText(QApplication::translate("CToolBox", "Select", Q_NULLPTR));
        radioBtnObject->setText(QApplication::translate("CToolBox", "Object", Q_NULLPTR));
        radioBtnLine->setText(QApplication::translate("CToolBox", "Line", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CToolBox: public Ui_CToolBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTOOLBOX_H
