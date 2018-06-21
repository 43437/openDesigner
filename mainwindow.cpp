#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pDlgToolBox(0),
    m_eEdtMode(eObject)
{
    ui->setupUi(this);

    m_pDlgToolBox = new CToolBox();
    createMenu();
}

void MainWindow::toolboxHandle(bool checked)
{
    if(checked)
    {
        m_pDlgToolBox->move(this->x(), this->geometry().y() + this->menuBar()->height());   //toolbox显示位置
        m_pDlgToolBox->show();
    }else
    {
        m_pDlgToolBox->hide();
    }
}

void MainWindow::createMenu()
{
    connect(ui->actionToolbox, SIGNAL(triggered(bool)), this, SLOT(toolboxHandle(bool)));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(NULL != m_pDlgToolBox)
    {
        delete m_pDlgToolBox;
        m_pDlgToolBox = NULL;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

}
