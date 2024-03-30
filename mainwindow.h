#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtextedit.h"
#include <QWidget>
#include <QFileDialog>
#include <QStandardPaths>
#include <fstream>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QTextEdit;
class QFileDialog;
class QStandardPaths;
class mainWindow : public QWidget
{
    std::string fileName;
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    void openDocument(QTextEdit *doc_box){
        //TODO: not just text files! do .doc as well?
        saveDocument(doc_box);
        doc_box->clear();
        std::string line;
        fileName = QFileDialog::getOpenFileName(this, "", "", "Text files (*.txt)").toStdString();
        std::ifstream file(fileName);
        doc_box->setText("");
        while(std::getline(file, line)){
            doc_box->append(QString::fromStdString(line));
        }
    }
    void createDocument(QTextEdit *doc_box){
        if (fileName != ""){
            saveDocument(doc_box);
            fileName = "";
        }
        doc_box->clear();
        return;
    }
    void saveDocument(QTextEdit *doc_box){
        QTextStream(stdout) << QString::fromStdString(fileName) << Qt::endl;
        if(fileName == ""){
            fileName = QFileDialog::getSaveFileName(this, "", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), "All Word Documents (*.doc, *.docx)").toStdString();
        }
        QTextStream(stdout) << QString::fromStdString(fileName) << Qt::endl;
        std::ofstream file(fileName);
        file << doc_box->toPlainText().toStdString();
        file.close();
    }
    void boldText(QTextEdit *doc_box){
        QTextCharFormat format = doc_box->textCursor().charFormat();
        if (format.fontWeight() == 75){
            format.setFontWeight(QFont::Normal);
        }
        else{
            format.setFontWeight(QFont::Bold);
        }
        doc_box->textCursor().setCharFormat(format);
        return;
    }
    void italicsText(QTextEdit *doc_box){
        QTextCharFormat format = doc_box->textCursor().charFormat();
        if (format.fontItalic()){
            format.setFontItalic(false);
        }
        else{
            format.setFontItalic(true);
        }
        doc_box->textCursor().setCharFormat(format);
        return;
    }
    void underlineText(QTextEdit *doc_box){
        QTextCharFormat format = doc_box->textCursor().charFormat();
        if (format.fontUnderline()){
            format.setFontUnderline(false);
        }
        else{
            format.setFontUnderline(true);
        }
        doc_box->textCursor().setCharFormat(format);
        return;
    }
    void highlightText(QTextEdit *doc_box){
        QTextCharFormat format = doc_box->textCursor().charFormat();
        QBrush colour = QBrush("green"); //allow for colour selection from user
        format.setBackground(colour);
        doc_box->textCursor().setCharFormat(format);
        return;
    }
    void colourText(QTextEdit *doc_box){
        QTextCharFormat format = doc_box->textCursor().charFormat(); //can use '.foreground() to check if foreground is set
        QBrush colour = QBrush("green"); //allow for colour selection from user
        format.setForeground(colour);
        doc_box->textCursor().setCharFormat(format);
        return;
    }
    void strikeText(QTextEdit *doc_box){
        QTextCharFormat format = doc_box->textCursor().charFormat();
        if (format.fontStrikeOut()){
            format.setFontStrikeOut(false);
        }
        else{
            format.setFontStrikeOut(true);
        }
        doc_box->textCursor().setCharFormat(format);
        return;
    }
    void sizeText(QTextEdit *doc_box){
        QTextStream(stdout) << doc_box->textCursor().charFormat().fontPointSize() << Qt::endl;
        QTextCharFormat format = doc_box->textCursor().charFormat();
        format.setFontPointSize(20);
        doc_box->textCursor().setCharFormat(format);
        return;
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



