#ifndef HEROES_CPP
#define HEROES_CPP
#include "heroes.h"

Hero::Hero(const string& name, const string& result) {
    heroName = name;
    setClass();
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
    winrate = 0.0;
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
    setType();
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
    winrate = 0.0;
}

void Map::setType() {
    if (mapName == "hanamura" || mapName == "templeofanibus" || mapName == "volskayaindustries") {
        mapType = "assault";
    }
    else if (mapName == "dorado" || mapName == "route66" || mapName == "watchpointgibraltar") {
        mapType = "escort";
    }
    else if (mapName == "eichenwalde" || mapName == "hollywood" || mapName == "kingsrow" || mapName == "numbani") {
        mapType = "hybrid";
    }
    else if (mapName == "oasis" || mapName == "ilios" || mapName == "nepal" || mapName == "lijiangtower") {
        mapType = "control";
    }
}
#endif
