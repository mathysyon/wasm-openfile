#include <iostream>
#include <fstream>
#include <QApplication>
#include <QMessageBox>
#include <QPushButton>
#include <qhtml5file/qhtmlfileaccess.h>
#include "mainwindow.h"

int main(int argc, char **argv){

    QApplication app(argc, argv);

#if 0
    QHtmlFileAccess *htmlFileAccess = new QHtmlFileAccess;

    auto btn = new QPushButton; //Créer un bouton => une fois cliqué, ouvre une boite de dialogue
    btn->setText("Open File");
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
        std::cout << "Path : " << qUtf8Printable(tmpFilePath) << std::endl;
        std::cout << "Name of file : "<< qUtf8Printable(fileName) << std::endl;
        std::string chemin = tmpFilePath.toStdString(); //Transforme un QString en String

        std::ifstream flux(chemin);
        if(flux)
        {
            std::string ligne;
            while(getline(flux, ligne))
            {
                std::cout << ligne << std::endl;
            }
        }
        else
        {
            std::cout << "Erreur, ouverture du fichier impossible."<< std::endl;
        }

    });

#endif

    MainWindow window;
    window.show();
    return app.exec();
}
