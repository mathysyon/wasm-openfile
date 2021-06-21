#pragma once

#include <QMainWindow>

class QHtmlFileAccess;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    class Ui_MainWindow *m_ui = nullptr;
    QHtmlFileAccess *m_htmlFileAccess = nullptr;
};

