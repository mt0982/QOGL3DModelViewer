#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QDebug>
#include <QFileDialog>

namespace Ui {
class Menu;
}

class Menu : public QWidget {
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

    /* Setters */
    void setWindowPosition(int w, int h);
    void setModelPath(const QString &value);

    /* Getters */
    int getAngle() const;
    QString getModelPath();

private slots:
    void on_dial_sliderMoved(int position);
    void on_buttonDiffuseMap_clicked();
    void on_buttonFile_clicked();

private:
    Ui::Menu *ui;
    int angle;
    QString modelPath;
};

#endif // MENU_H











