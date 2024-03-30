#include "mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTextEdit>

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
    QPushButton *bold_button = new QPushButton("<i>B</i>", this);
    QPushButton *underline_button = new QPushButton("U", this);
    QPushButton *highlight_button = new QPushButton("H", this); //choose better icon later
    QPushButton *colour_button = new QPushButton("C", this); //choose better icon later
    QPushButton *strike_button = new QPushButton("X", this); //OBVIOUSLY choose better icon later

    QFont bold_font = bold_button->font();
    bold_font.setBold(true);
    bold_button->setFont(bold_font);
    QPushButton *italics_button = new QPushButton("I", this);
    QFont italic_font = italics_button->font();
    italic_font.setItalic(true);
    italics_button->setFont(italic_font);

    button_box->addWidget(new_button);
    button_box->addWidget(open_button);
    button_box->addWidget(save_button);
    button_box->addWidget(bold_button);
    button_box->addWidget(italics_button);
    button_box->addWidget(underline_button);
    button_box->addWidget(highlight_button);
    button_box->addWidget(colour_button);
    button_box->addWidget(strike_button);

    connect(new_button, &QPushButton::clicked, this, [this, doc_box]() { createDocument(doc_box); });
    connect(open_button, &QPushButton::clicked, this, [this, doc_box]() { openDocument(doc_box); });
    connect(save_button, &QPushButton::clicked, this, [this, doc_box]() { saveDocument(doc_box); });
    connect(bold_button, &QPushButton::clicked, this, [this, doc_box]() { boldText(doc_box); });
    connect(italics_button, &QPushButton::clicked, this, [this, doc_box]() { italicsText(doc_box); });
    connect(underline_button, &QPushButton::clicked, this, [this, doc_box]() { underlineText(doc_box); });
    connect(highlight_button, &QPushButton::clicked, this, [this, doc_box]() { highlightText(doc_box); });
    connect(colour_button, &QPushButton::clicked, this, [this, doc_box]() { colourText(doc_box); });
    connect(strike_button, &QPushButton::clicked, this, [this, doc_box]() { strikeText(doc_box); });
}

