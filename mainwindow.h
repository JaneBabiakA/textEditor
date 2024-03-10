#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtextedit.h"
#include <QWidget>
#include <QFileDialog>
#include <fstream>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QTextEdit;
class QFileDialog;
class mainWindow : public QWidget
{
    std::string fileName;
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    void openDocument(QTextEdit *doc_box){
        saveDocument(doc_box);
        std::string line;
        fileName = QFileDialog::getOpenFileName(this, "", "", "Text files (*.txt)").toStdString();
        std::ifstream file(fileName);
        doc_box->setText("");
        while(std::getline(file, line)){
            doc_box->append(QString::fromStdString(line));
        }
    }
    void createDocument(){
        //if filename, save it and clear. also clear textbox
        return;
    }
    void saveDocument(QTextEdit *doc_box){
        QTextStream(stdout) << QString::fromStdString(fileName) << Qt::endl;
        if(fileName == ""){
            fileName = "C:\\Users\\janef\\Downloads\\saved_doc.txt";
        }
        QTextStream(stdout) << QString::fromStdString(fileName) << Qt::endl;
        std::ofstream file(fileName);
        file << doc_box->toPlainText().toStdString();
        file.close();
    }

private:
    QVBoxLayout *window_box;
    QHBoxLayout *button_box;
    QPushButton *new_button;
    QPushButton *open_button;
    QPushButton *save_button;
    QTextEdit *doc_box;
};
#endif // MAINWINDOW_H



