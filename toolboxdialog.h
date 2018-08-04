#ifndef TOOLBOXDIALOG_H
#define TOOLBOXDIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <vector>
#include <map>
#include "datadefinepub.h"

namespace Ui {
class ToolBoxDialog;
}

class ToolBoxDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ToolBoxDialog(QWidget *parent = 0);
    ~ToolBoxDialog();

private slots:
    void OnBtnToolChecked();

private:
    Ui::ToolBoxDialog *ui;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    int m_iMouseX, m_iMouseY;
    bool m_bMoveStarted;
    void init();
    std::map<QPushButton*, DATADEFINEPUB::ETOOLBTN> m_mapBtnTool;
};

#endif // TOOLBOXDIALOG_H
