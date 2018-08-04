#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "toolboxdialog.h"
#include "datadefinepub.h"
#include "model.h"
#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void OnMouseCursor(const DATADEFINEPUB::ETOOLBTN& eToolBtn);
    ~MainWindow();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void moveShape(CDistance* distance);

protected:
    void paintEvent(QPaintEvent* event);

private slots:
    void OnToolBoxEvent();

private:
    void init();
    Ui::MainWindow *ui;
    ToolBoxDialog m_dlgToolBox;
    DATADEFINEPUB::ETOOLBTN m_eToolBtn;
    std::map<long, CShape*> m_mapShape;
    CShape* m_pCurrShape;
};

#endif // MAINWINDOW_H
