#ifndef LOAD_CPP
#define LOAD_CPP

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Loader {
private:
    string result, map;
    int srChange, endRank, groupSize, teamSR, enemySR;
    vector<string> heroes;
    bool bLoaded;

public:
    Loader(int rowNum)
    {

        /*
           load line (game)
           parse line into:
           win/loss/tie
           change in sr
           end/current rank
           map
           heroes
           teamSR
           enemySR

           getter functions
           */
        ifstream file;
        string fileName = "stats.txt";
        file.open(fileName.c_str());
        string line;
        int count = 0;
        while (getline(file,line))
        {
            ++count;
        }

        file.close();
        //make sure can't ask for game that doesn't exist
        if (count < rowNum) {
            this->bLoaded = false;
            heroes.resize(3);
            return;
        }


        file.open("stats.txt");

        for(int i = 0; i < rowNum; ++i)
        {
            line.clear();

            (getline(file,line));
        }
        istringstream iss(line);
        iss >> result;
        iss >> srChange;
        iss >> endRank;
        iss >> map;
        iss >> groupSize;
        for (unsigned i = 0; i < 3; ++i)
        {
            string name;
            iss >> name;
            heroes.push_back(name);
        }
        iss >> teamSR;
        iss >> enemySR;

        this->bLoaded = true;
        file.close();
    }

    string         getResult() {return result;}
    int            getChange() {return srChange;}
    int            getEndRank() {return endRank;}
    string         getMap() {return map;}
    int            getGroupSize() {return groupSize;}
    vector<string> getHeroes() {return heroes;}
    int            getTeamSR() {return teamSR;}
    int            getEnemySR() {return enemySR;}

    void print()
    {
        cout << "Game result: " << getResult()
             << ". SR change: " << getChange()
             << ". Adjusted rank: " << getEndRank()
             << ". Map: " << getMap()
             << ". Party Size : " << getGroupSize()
             << ". Heroes played: " << heroes.at(0) << ", " << heroes.at(1) << ", " << heroes.at(2)
             << ". Team SR: " << teamSR
             << ". Enemy SR: " << enemySR << endl;
    }

    bool loaded() { return bLoaded;}

};
#endif
