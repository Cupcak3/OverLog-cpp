#include <iostream>
#include <vector>
#include <fstream>
#include "heroes.h"

class Data {
    private:
    vector<string> results;
    vector<int> SRs;
    vector<int> ranks;
    vector<Map*> maps;
    vector<int> groupSizes;
    vector<Hero*> heroes;
    int totalSRChange;
    vector<int> teamSRs;
    vector<int> enemySRs;

    public:
    Data();
    void pushing(const string& result, int SR, int rank, const string& map, int groupSize, const string& hero1, const string& hero2, const string& hero3, int teamSR, int enemySR);
    void getInput(const string& inputFile);
    void calculations();
    int getHeroSize();
    
    public:
    double heroWR;
    double tankWins;
    double tankLosses;
    double offenseWins;
    double offenseLosses;
    double defenseWins;
    double defenseLosses;
    double supportWins;
    double supportLosses;
    double bestWR;
    string bestHero;
    double worstWR;
    string worstHero;
    double mapWR, assaultWins, assaultLosses, escortWins, escortLosses, controlWins, controlLosses, hybridWins, hybridLosses;
    double bestmapWR;
    string bestMap;
    double worstmapWR;
    string worstMap;
    double supportWR;
    double offenseWR;
    double defenseWR;
    double tankWR;
    double assaultWR;
    double escortWR;
    double controlWR;
    double hybridWR;
    
};

int Data::getHeroSize() {
    return heroes.size();
}

//default constructor
Data::Data() {
    totalSRChange = 0;
    heroWR = 0.0;
    tankWins = 0.0;
    tankLosses = 0.0;
    offenseWins = 0.0;
    offenseLosses = 0.0;
    defenseWins = 0.0;
    defenseLosses = 0.0;
    supportWins = 0.0;
    supportLosses = 0.0;
    bestWR = 0.0;
    bestHero = "";
    worstWR = 100.0;
    worstHero = "";
    mapWR, assaultWins, assaultLosses, escortWins, escortLosses, controlWins, controlLosses, hybridWins, hybridLosses = 0.0;
    bestmapWR = 0.0;
    bestMap = "";
    worstmapWR = 100.0;
    worstMap = "";
    supportWR = 0.0;
    offenseWR = 0.0;
    defenseWR = 0.0;
    tankWR = 0.0;
    assaultWR = 0.0;
    escortWR = 0.0;
    controlWR = 0.0;
    hybridWR = 0.0;
}

//takes the data taken from the getInput function and puts it properly into the vectors
void Data::pushing(const string& result, int SR, int rank, const string& map, int groupSize, const string& hero1, const string& hero2, const string& hero3, int teamSR, int enemySR) {
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
    teamSRs.push_back(teamSR);
    enemySRs.push_back(enemySR);
}

void Data::calculations() { //calculates winrates per hero and map
    for (unsigned i = 0; i < heroes.size(); ++i) {
        heroWR = (static_cast<double>(heroes.at(i)->numWins)/(static_cast<double>(heroes.at(i)->numWins + heroes.at(i)->numLosses))) * 100;
        heroes.at(i)->winrate = heroWR;
        if (heroWR > bestWR) {
            bestWR = heroWR;
            bestHero = heroes.at(i)->heroName;
        }
        if (heroWR < worstWR) {
            worstWR = heroWR;
            worstHero = heroes.at(i)->heroName;
        }
        if (heroes.at(i)->heroClass == "offense") {
            offenseWins += heroes.at(i)->numWins;
            offenseLosses += heroes.at(i)->numLosses;
        }
        else if (heroes.at(i)->heroClass == "defense") {
            defenseWins += heroes.at(i)->numWins;
            defenseLosses += heroes.at(i)->numLosses;
        }
        else if (heroes.at(i)->heroClass == "tank") {
            tankWins += heroes.at(i)->numWins;
            tankLosses += heroes.at(i)->numLosses;
        }
        else if (heroes.at(i)->heroClass == "support") {
            supportWins += heroes.at(i)->numWins;
            supportLosses += heroes.at(i)->numLosses;
        }
    }
    offenseWR = offenseWins/(offenseLosses+offenseWins)*100;
    defenseWR = defenseWins/(defenseLosses+defenseWins)*100;
    tankWR = tankWins/(tankLosses+tankWins)*100;
    supportWR = supportWins/(supportLosses+supportWins)*100;
    for (unsigned i = 0; i < maps.size(); ++i) {
        mapWR = (static_cast<double>(maps.at(i)->numWins)/(static_cast<double>(maps.at(i)->numWins + maps.at(i)->numLosses))) * 100;
        maps.at(i)->winrate = mapWR;
        if (mapWR > bestmapWR) {
            bestmapWR = mapWR;
            bestMap = maps.at(i)->mapName;
        }
        if (mapWR < worstmapWR) {
            worstmapWR = mapWR;
            worstMap = maps.at(i)->mapName;
        }
        if (maps.at(i)->mapType == "assault") {
            assaultWins += maps.at(i)->numWins;
            assaultLosses += maps.at(i)->numLosses;
        }
        else if (maps.at(i)->mapType == "escort") {
            escortWins += maps.at(i)->numWins;
            escortLosses += maps.at(i)->numLosses;
        }
        else if (maps.at(i)->mapType == "control") {
            controlWins += maps.at(i)->numWins;
            controlLosses += maps.at(i)->numLosses;
        }
        else if (maps.at(i)->mapType == "hybrid") {
            hybridWins += maps.at(i)->numWins;
            hybridLosses += maps.at(i)->numLosses;
        }
    }
    assaultWR = assaultWins/(assaultLosses+assaultWins)*100;
    escortWR = escortWins/(escortLosses+escortWins)*100;
    controlWR = controlWins/(controlLosses+controlWins)*100;
    hybridWR =hybridWins/(hybridLosses+hybridWins)*100;
}
