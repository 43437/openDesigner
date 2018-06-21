#include "ctoolbox.h"
#include "ui_ctoolbox.h"

CToolBox::CToolBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CToolBox),
    m_iMouseX(0),
    m_iMouseY(0),
    m_edtMode(eSelect)
{
    ui->setupUi(this);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);
    this->setFixedSize(this->width(), this->height());

//    this->move(parent->x(),  parent->y());

    init();
}

void CToolBox::init()
{
    connect(ui->radioBtnObject, SIGNAL(toggled(bool)), this, SLOT(on_radioBtn_clicked()));
    connect(ui->radioBtnSelect, SIGNAL(toggled(bool)), this, SLOT(on_radioBtn_clicked()));
    connect(ui->radioBtnLine, SIGNAL(toggled(bool)), this, SLOT(on_radioBtn_clicked()));

    m_mapRadioButtons[eSelect] = ui->radioBtnSelect;
    m_mapRadioButtons[eLine] = ui->radioBtnLine;
    m_mapRadioButtons[eObject] = ui->radioBtnObject;

    ui->radioBtnSelect->setChecked(true);
}

CToolBox::~CToolBox()
{
    delete ui;
}

void CToolBox::mousePressEvent(QMouseEvent *event)
{
    m_iMouseX = event->x();
    m_iMouseY = event->y();
}

void CToolBox::mouseMoveEvent(QMouseEvent *event)
{
    int iCurX = this->x();
    int iCurY = this->y();

    iCurX += (event->x() - m_iMouseX);
    iCurY += (event->y() - m_iMouseY);
    this->move(iCurX, iCurY);
}

void CToolBox::on_radioBtn_clicked()
{
    for(std::map<EEditMode, QRadioButton*>::iterator it = m_mapRadioButtons.begin(); it != m_mapRadioButtons.end(); it++)
    {
        if(it->second->isChecked())
        {
            m_edtMode = it->first;
            break;
        }
    }
}
