#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractSpinBox>
#include <QKeyEvent>
#include <QMessageBox>
#include <algorithm>
#include "src/SaveAndLoad/save.cpp"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    //Picture on main page
    QPixmap picture("/Users/Alec/Documents/Projects/OverLog/resources/smeg.png"); //YOU MAY HAVE TO CHANGE THIS DIRECTOR TO POINT TOWARDS THE RESOURCES FOLDER
    ui->pictureLabel->setPixmap(picture);

    //Get rid of up/down arrows on the SR boxes
    foreach (QSpinBox *sBox, this->findChildren<QSpinBox*>()) sBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

    //Connect buttons to functionality
    connect(ui->exitButton, SIGNAL (clicked()), this, SLOT (close()));
    connect(ui->saveButton, SIGNAL (clicked()), this, SLOT(saveGame()));

    //Resize all columns correctly in history tab
    ui->historyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetTab1()
{


    foreach (QComboBox *widget, this->ui->enterTab->findChildren<QComboBox*>())  //findChildren<QComboBox*>())
        widget->setCurrentIndex(0);

    foreach (QRadioButton *radio, this->ui->enterTab->findChildren<QRadioButton*>())
    {
        radio->setAutoExclusive(false);
        radio->setChecked(false);
        radio->setAutoExclusive(true);
    }

    foreach (QSpinBox *spin, this->ui->enterTab->findChildren<QSpinBox*>())
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
        else if(heroes.at(i) == "Lúcio") heroes.at(i) = "lucio";
        else if(heroes.at(i) == "Torbjörn") heroes.at(i) = "torbjorn";
        else if(heroes.at(i) == "Soldier: 76") heroes.at(i) = "soldier76";
    }

    string mapName = ui->mapComboBox->currentText().toStdString();

    mapName.erase(std::remove(mapName.begin(), mapName.end(), ' '), mapName.end());
    mapName.erase(std::remove(mapName.begin(), mapName.end(), ':'), mapName.end());
    cout << "mapName: " << mapName << endl;

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
               mapName,
               ui->groupSizeComboBox->currentText().toInt(),
               heroes,
               ui->teamSRSpinBox->value(),
               ui->enemySRSpinBox->value());
    game.save();
    QMessageBox popup;
    popup.setText("Game saved!");
    popup.exec();

    resetTab1();
}


