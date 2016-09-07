#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent): QWidget(parent), ui(new Ui::Menu)
{
    ui->setupUi(this);

    angle = 0;
}

Menu::~Menu()
{
    delete ui;
}

void Menu::setWindowPosition(int w, int h)
{
    /* Set Window Size */
    setFixedSize(200, h);
    //setWindowPosition(w, h);
}

void Menu::on_dial_sliderMoved(int position)
{
    /* Set Angle */
    angle = position;
    qDebug() << angle;
}

int Menu::getAngle() const
{
    return angle;
}

























