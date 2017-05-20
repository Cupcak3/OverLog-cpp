#include "heroes.h"

Hero::Hero(const string& name, const string& result) {
    heroName = name;
    heroClass = "";
    if (result == "win") {
        numLosses = 0;
        numWins = 1;
        numTies = 0;
    }
    else if (result == "loss") {
        numLosses = 1;
        numWins = 0;
        numTies = 0;
    }
    else {
        numLosses = 0;
        numWins = 0;
        numTies = 1;
    }
}

void Hero::setClass() {
    if (heroName == "genji" || heroName == "mccree" || heroName == "soldier76" || heroName == "reaper" || heroName == "tracer" || heroName == "sombra" || heroName == "pharah") {
        heroClass = "offense";
    }
    else if (heroName == "hanzo" || heroName == "widowmaker" || heroName == "bastion" || heroName== "torbjorn" || heroName == "junkrat" || heroName == "mei") {
        heroClass = "defense";
    }
    else if (heroName == "orisa" || heroName == "dva" || heroName == "reinhardt" || heroName == "zarya" || heroName == "winston" || heroName == "roadhog") {
        heroClass = "tank";
    }
    else if (heroName == "symmetra" || heroName == "lucio" || heroName == "mercy" || heroName == "ana" || heroName == "zenyatta") {
        heroClass = "support";
    }
}

Map::Map(const string& name, const string& result) {
    mapName = name;
    if (result == "win") {
        numLosses = 0;
        numWins = 1;
        numTies = 0;
    }
    else if (result == "loss") {
        numLosses = 1;
        numWins = 0;
        numTies = 0;
    }
    else {
        numLosses = 0;
        numWins = 0;
        numTies = 1;
    }
}