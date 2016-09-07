#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent): QWidget(parent), ui(new Ui::Menu)
{
    ui->setupUi(this);

    setWindowTitle("Menu");
    angle = 0;
}

Menu::~Menu()
{
    delete ui;
}

void Menu::setWindowPosition(int w, int h)
{
    /* Set Window Size */
    setFixedSize(230, h);
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
    /* Get Angle */
    return angle;
}

void Menu::on_buttonFile_clicked()
{
    /* Open OBJ File */
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Model (*.obj)");
    modelPath = filename;

    /* File Name */
    QFileInfo file(filename);
    ui->labelFile->setText("Model File (*.obj): " + file.baseName().toLatin1());
}

void Menu::setModelPath(const QString &value)
{
    /* Clear Path | Multi Initialization Barrier */
    modelPath = value;
}

QString Menu::getModelPath()
{
    return modelPath;
}

void Menu::on_buttonDiffuseMap_clicked()
{
    /* Open Diffuse Map */
    QString filename = QFileDialog::getOpenFileName(this, "Open a File", "", "Model (*.jpg, *.png)");
    modelPath = filename;

    /* File Name */
    QFileInfo file(filename);
    setWindowTitle(file.baseName());
}













