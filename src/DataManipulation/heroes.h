#ifndef HEROES_H
#define HEROES_H
#include <string>
using namespace std;

struct Hero {
    string heroName;
    string heroClass;
    int numWins;
    int numLosses;
    int numTies;
    Hero(const string& name, const string& result);
    void setClass();
    double winrate;
};

struct Map {
    string mapName;
    string mapType;
    int numWins;
    int numLosses;
    int numTies;
    Map(const string& name, const string& result);
    void setType();
    double winrate;
};
#endif
