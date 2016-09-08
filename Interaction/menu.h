#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>
#include <QStyleFactory>

namespace Ui {
class Menu;
}

class Menu : public QWidget {
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

    /* Setters */
    void setWindowPosition(int x, int y, int h);
    void setModelPath(const QString &value);

    /* Getters */
    int getAngle() const;
    QString getModelPath();

    /* Public Variable */
    QString diffusePath;
    QString normalPath;
    QString ambientPath;
    QString specularPath;

private slots:
    void on_dial_sliderMoved(int position);
    void on_buttonDiffuseMap_clicked();
    void on_buttonFile_clicked();
    void on_buttonNormalMap_clicked();
    void on_buttonAmbientMap_clicked();
    void on_buttonSpecularMap_clicked();

private:
    Ui::Menu *ui;
    int angle;
    QString modelPath;
};

#endif // MENU_H











