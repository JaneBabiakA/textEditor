#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QFileDialog>

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *button_box = new QHBoxLayout(this);
    //QLineEdit *doc_box = new QLineEdit(this);
    QPushButton *new_button = new QPushButton("New", this);
    QPushButton *open_button = new QPushButton("Open", this);
    QPushButton *save_button = new QPushButton("Save", this);
    button_box->addWidget(new_button);
    button_box->addWidget(open_button);
    button_box->addWidget(save_button);
    connect(new_button, SIGNAL (clicked()), this, SLOT (createDocument()));
    connect(open_button, SIGNAL (clicked()), this, SLOT (openDocument()));
    connect(save_button, SIGNAL (clicked()), this, SLOT (saveDocument()));
}

