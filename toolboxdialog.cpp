#include "toolboxdialog.h"
#include "ui_toolboxdialog.h"
#include "mainwindow.h"

ToolBoxDialog::ToolBoxDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ToolBoxDialog),
    m_iMouseX(0),
    m_iMouseY(0),
    m_bMoveStarted(false)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);

    init();
}

ToolBoxDialog::~ToolBoxDialog()
{
    delete ui;
}

void ToolBoxDialog::init()
{
    m_mapBtnTool.insert(std::pair<QPushButton*, DATADEFINEPUB::ETOOLBTN>(ui->ID_BTN_CURSOR, DATADEFINEPUB::eToolBtnCursor));
    m_mapBtnTool.insert(std::pair<QPushButton*, DATADEFINEPUB::ETOOLBTN>(ui->ID_BTN_DRAW, DATADEFINEPUB::eToolBtnDraw));
    m_mapBtnTool.insert(std::pair<QPushButton*, DATADEFINEPUB::ETOOLBTN>(ui->ID_BTN_SELECT, DATADEFINEPUB::eToolBtnSelect));
    m_mapBtnTool.insert(std::pair<QPushButton*, DATADEFINEPUB::ETOOLBTN>(ui->ID_BTN_MOVE, DATADEFINEPUB::eToolBtnMove));
    connect(ui->ID_BTN_CURSOR, SIGNAL(toggled(bool)), this, SLOT(OnBtnToolChecked()));
    connect(ui->ID_BTN_DRAW, SIGNAL(toggled(bool)), this, SLOT(OnBtnToolChecked()));
    connect(ui->ID_BTN_SELECT, SIGNAL(toggled(bool)), this, SLOT(OnBtnToolChecked()));
    connect(ui->ID_BTN_MOVE, SIGNAL(toggled(bool)), this, SLOT(OnBtnToolChecked()));
}

void ToolBoxDialog::OnBtnToolChecked()
{
   DATADEFINEPUB::ETOOLBTN eBtnChecked = DATADEFINEPUB::eToolBtnNone;
    for(std::map<QPushButton*, DATADEFINEPUB::ETOOLBTN>::iterator it=m_mapBtnTool.begin(); it!= m_mapBtnTool.end(); it++)
    {
        if(it->first->isChecked())
        {
            eBtnChecked = it->second;
            break;
        }
    }
    MainWindow *mainWin = static_cast<MainWindow*>(this->parent());
    if(nullptr != mainWin)
    {
        mainWin->OnMouseCursor(eBtnChecked);
    }
}

void ToolBoxDialog::mousePressEvent(QMouseEvent *event)
{
    switch(event->button())
    {
        case Qt::LeftButton:
            m_bMoveStarted = true;
            m_iMouseX = event->globalX();
            m_iMouseY = event->globalY();
            break;
        default:
            break;
    }
}

void ToolBoxDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bMoveStarted)
    {
        int iWindowX = this->x();
        int iWindowY = this->y();
        int iMoveX = event->globalX() - m_iMouseX;
        int iMoveY = event->globalY() - m_iMouseY;
        iWindowX += iMoveX;
        iWindowY += iMoveY;
        this->move(iWindowX, iWindowY);

        m_iMouseX = event->globalX();
        m_iMouseY = event->globalY();
    }
}

void ToolBoxDialog::mouseReleaseEvent(QMouseEvent *event)
{
    switch (event->button()) {
    case Qt::LeftButton:
        m_bMoveStarted = false;
        break;
    default:
        break;
    }
}
