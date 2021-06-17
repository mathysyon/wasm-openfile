#include <iostream>
#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
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
        QMessageBox::StandardButtons buttons)
{
    auto msgBox = new QMessageBox(QMessageBox::Information,
                                  title, text, buttons, parent);
    asyncDialogExec(msgBox);
    return msgBox;
}

int main(int argc, char **argv){

    for(int i=0; i<argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }
    // std::cout << "Bonjour" << std::endl;

    QApplication app(argc, argv);
#if 0
    QFileDialog* fileDlg = new QFileDialog(nullptr);
    fileDlg->setFileMode(QFileDialog::AnyFile);
    fileDlg->setWindowTitle("Selection de fichier");
    fileDlg->setNameFilter("Any files (*)");
    asyncDialogExec(fileDlg);
 #endif
    //QString FilePATH = QFileDialog::getOpenFileName();
    //std::string strFilePATH = FilePATH.toStdString();
    //std::cout << strFilePATH << std::endl;

    QHtmlFileAccess *htmlFileAccess = new QHtmlFileAccess;
    //QHtmlFileAccess htmlFileAccess;

    auto btn = new QPushButton; //Créer un bouton => une fois cliqué, ouvre une boite de dialogue
    btn->setText("OpenFile");
    btn->show();
    QObject::connect(btn, &QPushButton::clicked, [=]{
        std::cout << "Bouton Cliqué" << std::endl;
        //htmlFileAccess->loadFsFile("*.*", "/tmp");
        htmlFileAccess->loadFile("*.*");
        });

//    QObject::connect(htmlFileAccess, &QHtmlFileAccess::fileDataReady, []{
//        std::cout << "hehe" << std::endl;
//        });
//        fileDataReady n'est pas appelé par loadFsFile

    QObject::connect(htmlFileAccess, &QHtmlFileAccess::fsFileReady, [](const QString &tmpFilePath, const QString &fileName){
        std::cout << qUtf8Printable(tmpFilePath) << std::endl;
        std::cout << qUtf8Printable(fileName) << std::endl;
        });


    return app.exec();
}
