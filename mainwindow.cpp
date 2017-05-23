#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractSpinBox>
#include <QKeyEvent>
#include <QMessageBox>
#include "src/SaveAndLoad/save.cpp"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);


    //Get rid of up/down arrows on the SR boxes
    foreach (QSpinBox *sBox, this->findChildren<QSpinBox*>()) sBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

    //Connect buttons to functionality
    connect(ui->exitButton, SIGNAL (clicked()), this, SLOT (close()));
    connect(ui->saveButton, SIGNAL (clicked()), this, SLOT(saveGame()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetWindow()
{
    cout << "RESETTING WINDOW" << endl;
    foreach (QComboBox *widget, this->findChildren<QComboBox*>())
        widget->setCurrentIndex(0);

    foreach (QRadioButton *radio, this->findChildren<QRadioButton*>())
    {
        radio->setAutoExclusive(false);
        radio->setChecked(false);
        radio->setAutoExclusive(true);
    }

    foreach (QSpinBox *spin, this->findChildren<QSpinBox*>())
        spin->setValue(0);
}

void MainWindow::saveGame()
{
    string result;
    vector<string> heroes;
    heroes.push_back(ui->hero1ComboBox->currentText().toStdString());
    heroes.push_back(ui->hero2ComboBox->currentText().toStdString());
    heroes.push_back(ui->hero3ComboBox->currentText().toStdString());

    for(int i = 0; i < heroes.size(); ++i)
    {
        if(heroes.at(i) == "Select a hero") heroes.at(i) = "null";
    }

    if(ui->radioLoss->isChecked()) result = "loss";
    else if(ui->radioTie->isChecked()) result = "tie";
    else if(ui->radioWin->isChecked()) result = "win";
    else
    {
        //window for warning
        QMessageBox popup;
        popup.setText("Please make sure you select if the game was a win, loss, or tie!");
        popup.exec();
        return;
    }

    Saver game(result,
               ui->srChangeSpinBox->value(),
               ui->srEndSpinBox->value(),
               ui->mapComboBox->currentText().toStdString(),
               ui->groupSizeComboBox->currentText().toInt(),
               heroes,
               ui->teamSRSpinBox->value(),
               ui->enemySRSpinBox->value());
    game.save();
    resetWindow();
}
