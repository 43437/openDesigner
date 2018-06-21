#ifndef CTOOLBOX_H
#define CTOOLBOX_H

#include <QDialog>
#include <QMouseEvent>
#include <map>
#include <QRadioButton>

namespace Ui {
class CToolBox;
}

typedef enum EEditMode{eSelect, eObject, eLine}EEditMode;

class CToolBox : public QDialog
{
    Q_OBJECT

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public:
    explicit CToolBox(QWidget *parent = 0);
    ~CToolBox();

private slots:
    void on_radioBtn_clicked();

private:
    Ui::CToolBox *ui;
    void init();
    int m_iMouseX;
    int m_iMouseY;
    EEditMode m_edtMode;
    std::map<EEditMode, QRadioButton*> m_mapRadioButtons;
};

#endif // CTOOLBOX_H
