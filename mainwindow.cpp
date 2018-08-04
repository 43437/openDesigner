#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "factory/cshapefactory.h"
#include <QPainter>
#include <QPen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_dlgToolBox(this),
    m_eToolBtn(DATADEFINEPUB::eToolBtnNone),
    m_pCurrShape(0)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnMouseCursor(const DATADEFINEPUB::ETOOLBTN &eToolBtn)
{
    m_eToolBtn = eToolBtn;
    switch(eToolBtn)
    {
    case DATADEFINEPUB::eToolBtnCursor:
        this->setCursor(Qt::ArrowCursor);
        break;
    case DATADEFINEPUB::eToolBtnDraw:
        this->setCursor(Qt::CrossCursor);
        break;
    case DATADEFINEPUB::eToolBtnSelect:
        this->setCursor(Qt::ArrowCursor);
        break;
    case DATADEFINEPUB::eToolBtnMove:
        this->setCursor(Qt::SizeAllCursor);
    default:
        break;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(NULL != m_pCurrShape)
    {
        QPainter painter(this);
        switch(m_eToolBtn)
        {
        case DATADEFINEPUB::eToolBtnSelect:
        case DATADEFINEPUB::eToolBtnDraw:
            m_pCurrShape->render(painter);
            break;
        default:
            break;
        }
    }

    QPainter painter(this);
    for(std::map<long, CShape*>::iterator it = m_mapShape.begin(); it != m_mapShape.end(); it++)
    {
        it->second->render(painter);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(NULL != m_pCurrShape)
    {
        delete m_pCurrShape;
    }
    switch(m_eToolBtn)
    {
    case DATADEFINEPUB::eToolBtnCursor:
        break;
    case DATADEFINEPUB::eToolBtnDraw:
        m_pCurrShape = CShapeFactory::genShape(DATADEFINEPUB::eShapeSegment);
        m_pCurrShape->setRect(QRect(event->pos(), event->pos()));
        break;
    case DATADEFINEPUB::eToolBtnSelect:
        m_pCurrShape = CShapeFactory::genShape(DATADEFINEPUB::eShapeSelect);
        m_pCurrShape->setRect(QRect(event->pos(), event->pos()));
        break;
    case DATADEFINEPUB::eToolBtnMove:
        m_pCurrShape = CShapeFactory::genShape(DATADEFINEPUB::eDistance);
        ((CDistance*)m_pCurrShape)->updatePos(event->pos(), event->pos());
        break;
    default:
        break;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    switch(m_eToolBtn)
    {
    case DATADEFINEPUB::eToolBtnCursor:
        break;
    case DATADEFINEPUB::eToolBtnDraw:
    case DATADEFINEPUB::eToolBtnSelect:
        m_pCurrShape->setRect(QRect(m_pCurrShape->getRect().topLeft(), event->pos()));
        break;
    case DATADEFINEPUB::eToolBtnMove:
        ((CDistance*)m_pCurrShape)->updatePos(event->pos());
        moveShape(((CDistance*)m_pCurrShape));
        ((CDistance*)m_pCurrShape)->updatePos(event->pos(), event->pos());
        break;
    default:
        break;
    }
    repaint();
}

void MainWindow::moveShape(CDistance* distance)
{
    for(std::map<long, CShape*>::iterator it = m_mapShape.begin(); it != m_mapShape.end(); it++)
    {
        if(it->second->getIsSelected())
        {
            it->second->updatePos(distance->getDistance().first, distance->getDistance().second);
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    QRect rect = QRect(0,0,0,0);
    if(NULL != m_pCurrShape)
    {
        rect = m_pCurrShape->getRect();
    }
    switch(m_eToolBtn)
    {
    case DATADEFINEPUB::eToolBtnCursor:
        break;
    case DATADEFINEPUB::eToolBtnDraw:
        if(rect.width() > VALID_SHAPE_SIZE && rect.height() > VALID_SHAPE_SIZE)
        {
            for(std::map<long, CShape*>::iterator it = m_mapShape.begin(); it != m_mapShape.end(); it++)
            {
                if(it->second->isConflict(rect))
                {
                    delete m_pCurrShape;
                    m_pCurrShape = NULL;
                    repaint();
                    return;
                }
            }
            int id = CShapeIdGenerator::getInstance().genId();
            if( id > 0 )
            {
                m_mapShape.insert(std::pair<long, CShape*>(id, m_pCurrShape));
                m_pCurrShape = NULL;
            }else
            {
                delete m_pCurrShape;
                m_pCurrShape = NULL;
            }
        }else
        {
            delete m_pCurrShape;
            m_pCurrShape = NULL;
        }
        break;
    case DATADEFINEPUB::eToolBtnSelect:
        for(std::map<long, CShape*>::iterator it = m_mapShape.begin(); it != m_mapShape.end(); it++)
        {
            it->second->setSelected(rect);
        }
        delete m_pCurrShape;
        m_pCurrShape = NULL;
        break;
    case DATADEFINEPUB::eToolBtnMove:
    default:
        delete m_pCurrShape;
        m_pCurrShape = NULL;
        break;
    }
    repaint();
}

void MainWindow::init()
{
    connect(ui->actionToolbox, SIGNAL(triggered(bool)), this, SLOT(OnToolBoxEvent()));
}

void MainWindow::OnToolBoxEvent()
{
    if(ui->actionToolbox->isChecked())
    {
        m_dlgToolBox.show();
    }else
    {
        m_dlgToolBox.hide();
    }
}
