#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ctoolbox.h"
#include "crectobj.h"
#include <map>
#include <vector>
#include "types.h"
#include "cwindowcallback.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void toolboxHandle(bool);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    class CMainWindowCallback : public CWindowCallback
    {
    public:
        CMainWindowCallback(MainWindow* caller);
        ~CMainWindowCallback();
        void CallBack();

    private:
        MainWindow *caller;
    };

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
    void createMenu();
    CToolBox *m_pDlgToolBox;
    EEditMode m_eEdtMode;
    EBUTTON m_eButton;
    CRectObj *m_rectObj;
    std::map<int, CRectObj*> m_mapRectObjs;

    int genKey();
    void releaseKey(int key);

    static int iSEED;
    const int BAG_SIZE;
    char m_cBag[512];
    CMainWindowCallback* m_callback;
};

#endif // MAINWINDOW_H
