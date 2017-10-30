#include <QApplication>
#include <QFile>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file(":/styles/theme_normal.qss");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString style(file.readAll());
        file.close();
    }
    else
    {
        QMessageBox::critical(nullptr, "Error", "Error loading style file: " +  file.errorString());
    }

    return app.exec();
}
