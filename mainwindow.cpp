
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QInputDialog>
#include <QSpinBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Ana");
    ui->comboBox->addItem("Bastion");
    ui->comboBox->addItem("D.Va");
    ui->comboBox->addItem("Genji");
    ui->comboBox->addItem("Hanzo");
    ui->comboBox->addItem("Junkrat");
    ui->comboBox->addItem("Lucio");
    ui->comboBox->addItem("Mccree");
    ui->comboBox->addItem("Mei");
    ui->comboBox->addItem("Mercy");
    ui->comboBox->addItem("Pharah");
    ui->comboBox->addItem("Orisa");
    ui->comboBox->addItem("Reaper");
    ui->comboBox->addItem("Reinhardt");
    ui->comboBox->addItem("Roadhog");
    ui->comboBox->addItem("Soldier: 76");
    ui->comboBox->addItem("Sombra");
    ui->comboBox->addItem("Symmetra");
    ui->comboBox->addItem("Torbjörn");
    ui->comboBox->addItem("Tracer");
    ui->comboBox->addItem("Widowmaker");
    ui->comboBox->addItem("Winston");
    ui->comboBox->addItem("Zarya");
    ui->comboBox->addItem("Zenyatta");

    ui->comboBox_2->addItem("Null");
    ui->comboBox_2->addItem("Ana");
    ui->comboBox_2->addItem("Bastion");
    ui->comboBox_2->addItem("D.Va");
    ui->comboBox_2->addItem("Genji");
    ui->comboBox_2->addItem("Hanzo");
    ui->comboBox_2->addItem("Junkrat");
    ui->comboBox_2->addItem("Lucio");
    ui->comboBox_2->addItem("Mccree");
    ui->comboBox_2->addItem("Mei");
    ui->comboBox_2->addItem("Mercy");
    ui->comboBox_2->addItem("Pharah");
    ui->comboBox_2->addItem("Orisa");
    ui->comboBox_2->addItem("Reaper");
    ui->comboBox_2->addItem("Reinhardt");
    ui->comboBox_2->addItem("Roadhog");
    ui->comboBox_2->addItem("Soldier: 76");
    ui->comboBox_2->addItem("Sombra");
    ui->comboBox_2->addItem("Symmetra");
    ui->comboBox_2->addItem("Torbjörn");
    ui->comboBox_2->addItem("Tracer");
    ui->comboBox_2->addItem("Widowmaker");
    ui->comboBox_2->addItem("Winston");
    ui->comboBox_2->addItem("Zarya");
    ui->comboBox_2->addItem("Zenyatta");

    ui->comboBox_3->addItem("Null");
    ui->comboBox_3->addItem("Ana");
    ui->comboBox_3->addItem("Bastion");
    ui->comboBox_3->addItem("D.Va");
    ui->comboBox_3->addItem("Genji");
    ui->comboBox_3->addItem("Hanzo");
    ui->comboBox_3->addItem("Junkrat");
    ui->comboBox_3->addItem("Lucio");
    ui->comboBox_3->addItem("Mccree");
    ui->comboBox_3->addItem("Mei");
    ui->comboBox_3->addItem("Mercy");
    ui->comboBox_3->addItem("Pharah");
    ui->comboBox_3->addItem("Orisa");
    ui->comboBox_3->addItem("Reaper");
    ui->comboBox_3->addItem("Reinhardt");
    ui->comboBox_3->addItem("Roadhog");
    ui->comboBox_3->addItem("Soldier: 76");
    ui->comboBox_3->addItem("Sombra");
    ui->comboBox_3->addItem("Symmetra");
    ui->comboBox_3->addItem("Torbjörn");
    ui->comboBox_3->addItem("Tracer");
    ui->comboBox_3->addItem("Widowmaker");
    ui->comboBox_3->addItem("Winston");
    ui->comboBox_3->addItem("Zarya");
    ui->comboBox_3->addItem("Zenyatta");


    //maps
    ui->comboBox_4->addItem("Dorado");
    ui->comboBox_4->addItem("Eichenwalde");
    ui->comboBox_4->addItem("Hanamura");
    ui->comboBox_4->addItem("Hollywood");
    ui->comboBox_4->addItem("Ilios");
    ui->comboBox_4->addItem("King's Row");
    ui->comboBox_4->addItem("Lijiang Tower");
    ui->comboBox_4->addItem("Temple of Anubis");
    ui->comboBox_4->addItem("Nepal");
    ui->comboBox_4->addItem("Volskaya Industries");
    ui->comboBox_4->addItem("Numbani");
    ui->comboBox_4->addItem("Oasis");
    ui->comboBox_4->addItem("Route 66");
    ui->comboBox_4->addItem("Watchpoint: Gibraltar");


        //group size
        ui->comboBox_5->addItem("1");
        ui->comboBox_5->addItem("2");
        ui->comboBox_5->addItem("3");
        ui->comboBox_5->addItem("4");
        ui->comboBox_5->addItem("5");
        ui->comboBox_5->addItem("6");

        //Win / Lose / Draw
        ui->comboBox_6->addItem("Win");
        ui->comboBox_6->addItem("Lose");
        ui->comboBox_6->addItem("Draw");


        ui->SR->setRange(0, 5000);


    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(on_pushButton_release()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_release(){
    QString hero1 = ui->comboBox->currentText();
    QString hero2 = ui->comboBox_2->currentText();
    QString hero3 = ui->comboBox_3->currentText();
    QString map = ui->comboBox_4->currentText();
    QString groupSize = ui->comboBox_5->currentText();
    QString matchOutcome = ui->comboBox_6->currentText();
    int srChange = ui->lineEdit->text().toInt();
    int endSr = ui->SR->value();

    cout << hero1.toStdString() << endl;
    cout << hero2.toStdString() << endl;
    cout << hero3.toStdString() << endl;
    cout << map.toStdString() << endl;
    cout << groupSize.toStdString() << endl;
    cout << matchOutcome.toStdString() << endl;
    cout << srChange << endl;
    cout << endSr << endl;

}
