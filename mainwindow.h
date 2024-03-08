#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "document.h"
#include <QFileDialog>
#include <fstream>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QLineEdit;
class QFileDialog;
class Document;
class mainWindow : public QWidget
{
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);

private slots:
    void createDocument(){
        QTextStream(stdout) << "new";
        // should save current document & then clear textbox
        return;
    }
    void openDocument(){
        std::string line;
        std::string fileName = QFileDialog::getOpenFileName(this, "", "", "Text files (*.txt)").toStdString();
        std::ifstream file(fileName);
        QTextStream out(stdout);
        while(std::getline(file, line)){
            out << QString::fromStdString(line);
        }
        return;
    }
    void saveDocument(){
        //saves document
        return;
    }
private:
    QVBoxLayout *window_box;
    QHBoxLayout *button_box;
    QPushButton *new_button;
    QPushButton *open_button;
    QPushButton *save_button;
    QLineEdit *doc_box;
};
#endif // MAINWINDOW_H



