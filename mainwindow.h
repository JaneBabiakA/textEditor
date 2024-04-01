#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qtextedit.h"
#include <QWidget>
#include <QFileDialog>
#include <QStandardPaths>
#include <QSpinBox>

class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QTextEdit;
class QFileDialog;
class QStandardPaths;
class QSpinBox;
class mainWindow : public QWidget
{
    QString fileName;
    Q_OBJECT
public:
    mainWindow(QWidget *parent = nullptr);
    void openDocument(QTextEdit *doc_box){
        //TODO: not just text files! do .doc as well?
        saveDocument(doc_box);
        doc_box->clear();
        std::string line;
        fileName = QFileDialog::getOpenFileName(this, "", "", "Text files (*.txt)");
        //std::ifstream file(fileName);
        doc_box->setText("");
        //while(std::getline(file, line)){
        //    doc_box->append(QString::fromStdString(line));
        //}
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
        if(fileName == ""){
            fileName = QFileDialog::getSaveFileName(this, "", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), "All Word Documents (*.doc, *.docx)");
        }
        QFile file(fileName);
        if (file.open(QFile::WriteOnly | QFile::Text)){
            QTextStream write(&file);
            write << doc_box->toHtml();
            file.flush();
            file.close();
        }
        //raise warning if file doesn't open?
    }
    void boldText(QTextEdit *doc_box){
        QTextCharFormat format = doc_box->textCursor().charFormat();
        if (format.fontWeight() == 700){
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
    void sizeText(QTextEdit *doc_box, int size){
        QTextCharFormat format = doc_box->textCursor().charFormat();
        QTextStream(stdout) << format.fontWeight() << " " << Qt::endl;
        QTextStream(stdout) << format.fontPointSize() << " " << Qt::endl;
        format.setFontPointSize(size);
        doc_box->textCursor().setCharFormat(format);
        QTextStream(stdout) << format.fontWeight() << " " << Qt::endl;
        QTextStream(stdout) << format.fontPointSize() << " " << Qt::endl;
        return;
    }

private:
    QVBoxLayout *window_box;
    QHBoxLayout *button_box;
    QPushButton *new_button;
    QPushButton *open_button;
    QPushButton *save_button;
    QTextEdit *doc_box;
    QSpinBox *size_button;
    QPushButton *bold_button;
    QPushButton *underline_button;
    QPushButton *highlight_button;
    QPushButton *colour_button;
    QPushButton *strike_button;

};
#endif // MAINWINDOW_H



