#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QDebug>

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

    /* Getters */
    int getAngle() const;

private slots:
    void on_dial_sliderMoved(int position);

private:
    Ui::Menu *ui;
    int angle;
};

#endif // MENU_H











