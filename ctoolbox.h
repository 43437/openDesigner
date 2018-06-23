#ifndef CTOOLBOX_H
#define CTOOLBOX_H

#include <QDialog>
#include <QMouseEvent>
#include <map>
#include <QRadioButton>
#include "cwindowcallback.h"
#include "types.h"

namespace Ui {
class CToolBox;
}

class CToolBox : public QDialog
{
    Q_OBJECT

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public:
    explicit CToolBox(QWidget *parent = 0);
    EEditMode getEditMode(){return this->m_edtMode;}
    void setEventCallback(CWindowCallback* callback){this->callback = callback;}
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
    CWindowCallback *callback;
};

#endif // CTOOLBOX_H
