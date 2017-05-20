#ifndef SAVER_H
#define SAVER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Saver
{
     private:
     void save();
     char result;
     int srChange, endRank, groupSize, teamSR, enemySR;
     string map;
     vector<string> heroes;
     
     public:
     Saver(){}
     Saver(char result, int srChange, int endRank, string map, int groupSize, vector<string> heroes){}
     Saver(char result, int srChange, int endRank, string map, int groupSize, vector<string> heroes, int teamSR, int enemySR){}
     
};
#endif
