#include "mainwindow.h"
#include <QPushButton>

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent)
{
    QPushButton *new_button = new QPushButton("New", this);
    //QPushButton *open_button = new QPushButton("Open", this);
    connect(new_button, SIGNAL (clicked()), this, SLOT (createDocument()));
}

