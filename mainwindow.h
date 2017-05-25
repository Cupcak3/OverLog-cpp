#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void saveGame();
    void onTabChanged(int);

private:
    Ui::MainWindow *ui;
    void resetTab1();
    QString fixString(std::string mapName);
};

#endif // MAINWINDOW_H
