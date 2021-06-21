#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QMessageBox>
#include <qhtml5file/qhtmlfileaccess.h>

void asyncDialogExec(QDialog *dialog)
{
    if (dialog != NULL) {
        dialog->setModal(true);
        QObject::connect(
                    dialog, &QDialog::finished,
                    dialog, &QObject::deleteLater,
                    Qt::UniqueConnection);
        dialog->show();
    }
}

QMessageBox* asyncMsgBoxInfo(
        QWidget* parent,
        const QString& title,
        const QString& text,
        QMessageBox::StandardButtons buttons=QMessageBox::Ok)
{
    auto msgBox = new QMessageBox(QMessageBox::Information,
                                  title, text, buttons, parent);
    asyncDialogExec(msgBox);
    return msgBox;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_htmlFileAccess(new QHtmlFileAccess(this))
{
    m_ui->setupUi(this);
    QObject::connect(m_ui->actionOpen, &QAction::triggered, [=]{
        m_htmlFileAccess->loadFsFile("*.*", "/tmp");
    });

    QObject::connect(m_ui->actionExit, &QAction::triggered, [=]{
        close();
    });

    QObject::connect(m_htmlFileAccess, &QHtmlFileAccess::fsFileReady, [=](const QString &tmpFilePath, const QString &fileName){
        std::cout << "Path : " << qUtf8Printable(tmpFilePath) << std::endl;
        std::cout << "Name of file : "<< qUtf8Printable(fileName) << std::endl;
        std::string chemin = tmpFilePath.toStdString(); //Transforme un QString en String
        QString fileContent;

        std::ifstream flux(chemin);
        if(flux)
        {
            std::string ligne;
            while(getline(flux, ligne))
            {
                //std::cout << ligne << std::endl;
                fileContent += QString::fromStdString(ligne) + "\n";
            }
        }
        else
        {
            asyncMsgBoxInfo(this, "Erreur", "Erreur, ouverture du fichier impossible");
        }
        m_ui->editor->setPlainText(fileContent);
    });
}

MainWindow::~MainWindow()
{
    delete m_ui;
}
