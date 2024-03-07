#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "document.h"

class QPushButton;
class Document;
class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);

private slots:
    void createDocument(){
        QTextStream(stdout) << "button pressed";
        return;
    }
private:
    QPushButton *new_button;
    QPushButton *open_button;
};
#endif // MAINWINDOW_H



