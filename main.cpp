#include <QApplication>
#include <QSurfaceFormat>
#include <glwidget.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSurfaceFormat format = QSurfaceFormat::defaultFormat();
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(4,5);
    QSurfaceFormat::setDefaultFormat(format);

    GLWidget w;
    w.show();

    return app.exec();
}
