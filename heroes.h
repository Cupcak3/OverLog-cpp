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
};

struct Map {
    string mapName;
    int numWins;
    int numLosses;
    int numTies;
    Map(const string& name, const string& result);
};
#endif