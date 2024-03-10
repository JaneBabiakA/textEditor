#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QFileDialog>

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *window_box = new QVBoxLayout(this);
    QHBoxLayout *button_box = new QHBoxLayout();
    QTextEdit *doc_box = new QTextEdit(this);
    window_box->addLayout(button_box);
    window_box->addWidget(doc_box);
    QPushButton *new_button = new QPushButton("New", this);
    QPushButton *open_button = new QPushButton("Open", this);
    QPushButton *save_button = new QPushButton("Save", this);
    button_box->addWidget(new_button);
    button_box->addWidget(open_button);
    button_box->addWidget(save_button);

    connect(new_button, &QPushButton::clicked, this, &mainWindow::createDocument);

    connect(open_button, &QPushButton::clicked, this, [this, doc_box]() {openDocument(doc_box);});

    connect(save_button, &QPushButton::clicked, this, [this, doc_box]() {saveDocument(doc_box);});
}

