#include <iostream>
#include <vector>
#include <fstream>
#include "heroes.h"

class Data {
    public:
    vector<string> results;
    vector<int> SRs;
    vector<int> ranks;
    vector<Map*> maps;
    vector<int> groupSizes;
    vector<Hero*> heroes;
    int totalSRChange;
    
    public:
    Data();
    void pushing(const string& result, int SR, int rank, const string& map, int groupSize, const string& hero1, const string& hero2, const string& hero3);
};

//default constructor
Data::Data() {
    totalSRChange = 0;
}

//takes the data taken from the getInput function and puts it properly into the vectors
void Data::pushing(const string& result, int SR, int rank, const string& map, int groupSize, const string& hero1, const string& hero2, const string& hero3) {
    bool mapAdded = false;
    bool heroAdded = false;
    results.push_back(result);
    if (results.back() == "loss") { //makes SR negative if the match was a loss
        SR *= -1;
    }
    SRs.push_back(SR);
    ranks.push_back(rank);
    for (unsigned i = 0; i < maps.size(); ++i) { //checks if map is already in list and increments win/loss/tie
        if (maps.at(i)->mapName == map) {
            if (result == "win") {
                maps.at(i)->numWins += 1;
            }
            else if (result == "loss") {
                maps.at(i)->numLosses += 1;
            }
            else {
                maps.at(i)->numTies += 1;
            }
            i = maps.size();
            mapAdded = true;
        }
    }
    if (!mapAdded) { //if the map was not found, it adds a map object to the vector
        maps.push_back(new Map(map, result));
    }
    groupSizes.push_back(groupSize);
    for (unsigned i = 0; i < heroes.size(); ++i) { //checks if hero is already in list and increments win/loss/tie
        if (heroes.at(i)->heroName == hero1) {
            if (result == "win") {
                heroes.at(i)->numWins += 1;
            }
            else if (result == "loss") {
                heroes.at(i)->numLosses += 1;
            }
            else {
                heroes.at(i)->numTies += 1;
            }
            i = heroes.size();
            heroAdded = true;
        }
    }
    if (!heroAdded) { //if the hero was not found, it adds a hero object to the vector and sets its class
        heroes.push_back(new Hero(hero1, result));
        heroes.back()->setClass();
    }
    heroAdded = false;
    if (hero2 != "null") {
        for (unsigned i = 0; i < heroes.size(); ++i) {
            if (heroes.at(i)->heroName == hero2) {
                if (result == "win") {
                    heroes.at(i)->numWins += 1;
                }
                else if (result == "loss") {
                    heroes.at(i)->numLosses += 1;
                }
                else {
                    heroes.at(i)->numTies += 1;
                }
                i = heroes.size();
                heroAdded = true;
            }
        }
        if (!heroAdded) {
            heroes.push_back(new Hero(hero2, result));
            heroes.back()->setClass();
        }
    }
    heroAdded = false;
    if (hero3 != "null") {
        for (unsigned i = 0; i < heroes.size(); ++i) {
            if (heroes.at(i)->heroName == hero3) {
                if (result == "win") {
                    heroes.at(i)->numWins += 1;
                }
                else if (result == "loss") {
                    heroes.at(i)->numLosses += 1;
                }
                else {
                    heroes.at(i)->numTies += 1;
                }
                i = heroes.size();
                heroAdded = true;
            }
        }
        if (!heroAdded) {
            heroes.push_back(new Hero(hero3, result));
            heroes.back()->setClass();
        }
    }
    totalSRChange += SR;
}

