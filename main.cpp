#include <QApplication>
#include <login.h>

int main(int argc, char *argv[])
{
    // Open the login form.
    QApplication app(argc, argv);
    Login form;
    form.show();
    return app.exec();
}
