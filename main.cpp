#include <iostream>
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include <qhtml5file/qhtmlfileaccess.h>

int main(int argc, char **argv){

    for(int i=0; i<argc; ++i)
    {
        std::cout << argv[i] << std::endl;
    }

    QApplication app(argc, argv);

    QHtmlFileAccess *htmlFileAccess = new QHtmlFileAccess;

    auto btn = new QPushButton; //Créer un bouton => une fois cliqué, ouvre une boite de dialogue
    btn->setText("Open a File");
    btn->show();
    QObject::connect(btn, &QPushButton::clicked, [=]{
        std::cout << "Bouton Cliqué" << std::endl;
        htmlFileAccess->loadFsFile("*.*", "/tmp");
        //htmlFileAccess->loadFile("*.*"); //??
        });

//    QObject::connect(htmlFileAccess, &QHtmlFileAccess::fileDataReady, []{
//        std::cout << "hehe" << std::endl;
//        });
//        fileDataReady n'est pas appelé par loadFsFile

    QObject::connect(htmlFileAccess, &QHtmlFileAccess::fsFileReady, [](const QString &tmpFilePath, const QString &fileName){
        std::cout << qUtf8Printable(tmpFilePath) << std::endl; //Affiche le chemin du fichier
        std::cout << qUtf8Printable(fileName) << std::endl; //Affiche le nom du fichier
        });


    return app.exec();
}
