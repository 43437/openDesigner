#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPen>
#include <QBrush>
#include <QPainter>

int MainWindow::iSEED = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_pDlgToolBox(0),
    m_eEdtMode(eObject),
    m_eButton(eNoBtn),
    m_rectObj(0),
    BAG_SIZE(4096)
{
    memset(m_cBag, 0, 512);
    ui->setupUi(this);
    m_callback = new CMainWindowCallback(this);

    m_pDlgToolBox = new CToolBox();
    m_pDlgToolBox->setEventCallback(m_callback);
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

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QBrush brush;

    painter.setBrush(brush);
    painter.setPen(pen);

    for(std::map<int, CRectObj*>::iterator it=m_mapRectObjs.begin(); it!=m_mapRectObjs.end(); it++)
    {
        painter.drawRect(it->second->getRect());
    }

    if(NULL != m_rectObj)
    {
        painter.drawRect(m_rectObj->getRect());
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        m_eButton = eLeftBtn;
        switch(m_pDlgToolBox->getEditMode())
        {
        case eObject:
            if(NULL == m_rectObj)
            {
                m_rectObj = new CRectObj();
            }

            m_rectObj->setTopLeft(event->pos());

            break;
        case eSelect:
            break;
        case eLine:
            break;
        default:
            break;
        }
        break;
    case Qt::RightButton:
        m_eButton = eRightBtn;
        break;
    default:
        break;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    switch (m_eButton) {
    case eLeftBtn:
        switch(m_pDlgToolBox->getEditMode())
        {
        case eObject:
            if(NULL == m_rectObj)
            {
                return;
            }
            m_rectObj->setBottomRight(event->pos());
            repaint();

            break;
        case eSelect:
            break;
        case eLine:
            break;
        default:
            break;
        }

        break;
    case eRightBtn:

        break;
    default:
        break;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    switch(m_eButton)
    {
    case eLeftBtn:
        switch (m_pDlgToolBox->getEditMode()) {
        case eObject:
            if(NULL == m_rectObj)
            {
                return;
            }
            m_rectObj->setBottomRight(event->pos());

            {
                bool bIsValid = true;
                int id = -1;

                QRect rect = m_rectObj->getRect();
                if(rect.width()>OBJ_MIN_SIZE && rect.height()>OBJ_MIN_SIZE)
                {
                    for(std::map<int, CRectObj*>::iterator it = m_mapRectObjs.begin(); it != m_mapRectObjs.end(); it++)
                    {
                        if(m_rectObj->isConflict(it->second->getRect()))
                        {
                            bIsValid = false;
                            break;
                        }
                    }
                }else
                {
                    bIsValid = false;
                }

                if(bIsValid)
                {
                    id = genKey();
                    if(id<0)
                    {
                        delete m_rectObj;
                        m_rectObj = NULL;
                        repaint();
                        return;
                    }
                }else
                {
                    delete m_rectObj;
                    m_rectObj = NULL;
                    repaint();
                    return;
                }

                m_mapRectObjs.insert(std::pair<int, CRectObj*>(id, m_rectObj));
                m_rectObj = NULL;
            }
            repaint();
            break;

        case eSelect:
            break;
        default:
            break;
        }


        break;
    case eRightBtn:
        break;
    default:
        break;
    }

    m_eButton = eNoBtn;
}

int MainWindow::genKey()
{
    for(int i=0; i<BAG_SIZE; i++, iSEED++)
    {
        iSEED %= BAG_SIZE;
        if (!(m_cBag[iSEED/8] & (1 << (iSEED%8))))
        {
            m_cBag[iSEED/8] |= (1 << (iSEED%8));
            return iSEED;
        }
    }

    return -1;
}

void MainWindow::releaseKey(int key)
{
    if( key < 0 || key >= BAG_SIZE )
    {
        return;
    }

    m_cBag[key/8] &= (~(1 << (key%8)));
}

MainWindow::CMainWindowCallback::CMainWindowCallback(MainWindow* caller)
{
    this->caller = caller;
}

MainWindow::CMainWindowCallback::~CMainWindowCallback()
{
    ;
}

void MainWindow::CMainWindowCallback::CallBack() {
    switch(caller->m_pDlgToolBox->getEditMode())
    {
    case eObject:
    case eLine:
        caller->setCursor(Qt::CrossCursor);
        break;
    case eSelect:
    default:
        caller->setCursor(Qt::ArrowCursor);
        break;
    }
}
