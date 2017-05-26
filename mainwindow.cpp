#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QAbstractSpinBox>
#include <QKeyEvent>
#include <QMessageBox>
#include <algorithm>

#include "src/SaveAndLoad/save.cpp"
#include "src/SaveAndLoad/load.cpp"


using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Picture on main page
    QPixmap picture("/Users/Alec/Documents/Projects/OverLog/resources/background.png"); //YOU MAY HAVE TO CHANGE THIS DIRECTOR TO POINT TOWARDS THE RESOURCES FOLDER
    ui->pictureLabel->setPixmap(picture);

    //Get rid of up/down arrows on the SR boxes
    foreach (QSpinBox *sBox, this->findChildren<QSpinBox*>()) sBox->setButtonSymbols(QAbstractSpinBox::NoButtons);

    //Connect buttons to functionality
    connect(ui->exitButton, SIGNAL (clicked()), this, SLOT (close()));
    connect(ui->saveButton, SIGNAL (clicked()), this, SLOT(saveGame()));
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT (onTabChanged(int)));

    //Resize all columns correctly in history tab
    ui->historyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    reloadData();
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
    reloadData();
}

void MainWindow::reloadData()
{

    unsigned i = 1;
    bool flag = true;
    unsigned rank;
    for(i = 1; flag; ++i)
    {
        Loader game(i);
        bool flag = game.loaded();
        if(!flag)
        {
            rank = 0;
            break;
        }

        rank = game.getEndRank();
    }
    ui->skillRankDisplay->setText(QString::number(rank));
    QPixmap picture;
    int w = ui->rankSymbolLabel->width();
    int h = ui->rankSymbolLabel->height();
    if(rank <= 1499) picture.load("/Users/Alec/Documents/Projects/OverLog/resources/bronze.png");
    else if(rank >= 1500 && rank <= 1999) picture.load("/Users/Alec/Documents/Projects/OverLog/resources/silver.png");
    else if(rank >= 2000 && rank <= 2499) picture.load("/Users/Alec/Documents/Projects/OverLog/resources/gold.png");
    else if(rank >= 2500 && rank <= 2999) picture.load("/Users/Alec/Documents/Projects/OverLog/resources/platinum.png");
    else if(rank >= 3000 && rank <= 3499) picture.load("/Users/Alec/Documents/Projects/OverLog/resources/diamond.png");
    else if(rank >= 3500 && rank <= 3999) picture.load("/Users/Alec/Documents/Projects/OverLog/resources/master.png");
    else picture.load("/Users/Alec/Documents/Projects/OverLog/resources/grandmaster.png");

    ui->rankSymbolLabel->setPixmap(picture.scaled(w,h));
}

QString MainWindow::fixString(string word)
{
    if(word == "dorado" || word == "eichenwalde" || word == "hanamura"
            || word == "hollywood" || word == "hollywood" || word == "ilios"
            || word == "numbani" || word == "oasis"

            || word == "ana" || word == "bastion" || word == "genji" || word == "hanzo"
            || word == "junkrat" || word == "mccree" || word == "mei" || word == "mercy"
            || word == "orisa" || word == "pharah" || word == "reaper" || word == "reinhardt"
            || word == "roadhog" || word == "sombra" || word == "symmetra" || word == "tracer"
            || word == "widowmaker" || word == "winston" || word == "zarya" || word == "zenyatta"

            || word == "tie" || word == "win" || word == "loss")
        word[0] = toupper(word[0]);
    else if(word == "kingsrow") word = "King's Row";
    else if(word == "lijiangtower") word = "Lijiang Tower";
    else if(word == "route66") word = "Route 66";
    else if(word == "templeofanubis") word = "Temple of Anubis";
    else if(word == "volskayaindustries") word = "Volskaya Industries";
    else if(word == "watchpointgibraltar") word = "Watchpoint: Gibraltar";
    else if(word == "dva") word = "D.Va";
    else if(word == "lucio") word = "Lúcio";
    else if(word == "torbjorn") word = "Torbjörn";
    else if(word == "soldier76") word = "Soldier: 76";



    return QString::fromStdString(word);
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
        else if(heroes.at(i) == "D.Va") heroes.at(i) = "dva";
    }

    string mapName = ui->mapComboBox->currentText().toStdString();

    mapName.erase(std::remove(mapName.begin(), mapName.end(), ' '), mapName.end());
    mapName.erase(std::remove(mapName.begin(), mapName.end(), ':'), mapName.end());
    mapName.erase(std::remove(mapName.begin(), mapName.end(), '\''), mapName.end());

    if(ui->radioLoss->isChecked()) result = "loss";
    else if(ui->radioTie->isChecked()) result = "tie";
    else if(ui->radioWin->isChecked()) result = "win";
    else
    {
        //window for warning
        QMessageBox popup;
        popup.setText("Please make sure you select if the game was a win, loss, or tie!");
        popup.exec();
        resetTab1();
        return;
    }

    if((ui->radioLoss->isChecked() && ui->srChangeSpinBox >= 0) ||
            (ui->radioTie->isChecked() && ui->srChangeSpinBox != 0) ||
            (ui->radioWin->isChecked() && ui->srChangeSpinBox <= 0))
    {
        QMessageBox popup;
        popup.setWindowTitle("Error");
        popup.setText("Invalid game entry detected. Make sure to check the result of the game and the points you gained or lost.");
        popup.exec();
        resetTab1();
        return;
    }
    unsigned endSR = 0;
    if(ui->srEndSpinBox->value() < 1) endSR = 1;
    else endSR = ui->srEndSpinBox->value();

    Saver game(result,
               ui->srChangeSpinBox->value(),
               endSR,
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

void MainWindow::onTabChanged(int tabIndex)
{
    reloadData();


    if(tabIndex == 1)
    {
        ui->historyTable->setRowCount(0);

        //Load games
        unsigned i = 1;
        bool flag = true;
        for(i = 1; flag; ++i)
        {
            Loader game(i);

            flag = game.loaded();
            if(!flag) break;
            //put game into Data object
            /*
            data.pushing(game.getResult(),
                         game.getChange(),
                         game.getEndRank(),
                         game.getMap(),
                         game.getGroupSize(),
                         game.getHeroes().at(0),
                         game.getHeroes().at(1),
                         game.getHeroes().at(2),
                         game.getTeamSR(),
                         game.getEnemySR());
                         */

            QString mapName = fixString(game.getMap());
            QString hero1Name = fixString(game.getHeroes().at(0));
            QString hero2Name, hero3Name;
            QString result = fixString(game.getResult());
            if(game.getHeroes().at(1) != "null") hero2Name = fixString(game.getHeroes().at(1));
            if(game.getHeroes().at(2) != "null") hero3Name = fixString(game.getHeroes().at(2));

            ui->historyTable->insertRow(i-1);
            for(int j = 0; j < ui->historyTable->columnCount(); ++j)
            {
                QTableWidgetItem *pCell = ui->historyTable->item(i-1,j);

                if(!pCell)
                {
                    pCell = new QTableWidgetItem;
                    ui->historyTable->setItem(i-1, j, pCell);
                }

                switch (j)
                {
                case 0: pCell->setText(QString::number(i)); break; // to be filled in later
                case 1: pCell->setText(mapName); break;
                case 2: pCell->setText(result); break;
                case 3: pCell->setText(QString::number(game.getEndRank())); break;
                case 4: pCell->setText(hero1Name); break;
                case 5:
                {
                    if(game.getHeroes().at(1) != "null")
                    {
                        pCell->setText(hero2Name);
                    }
                    break;
                }
                case 6:
                {
                    if(game.getHeroes().at(2) != "null")
                    {
                        pCell->setText(hero3Name);
                    }
                    break;
                }
                case 7: pCell->setText(QString::number(game.getTeamSR())); break;
                case 8: pCell->setText(QString::number(game.getEnemySR())); break;
                default: break;
                }

                pCell->setTextAlignment(Qt::AlignCenter);


            }

        }

    }
    else if(tabIndex == 2)
    {

    }
    else if(tabIndex == 3)
    {

    }
}


