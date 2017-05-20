#include "save.h"
#include <fstream>
#include <iostream>

Saver::Saver(char result, double srChange, int endRank, string map, int groupSize, vector<string> heroes)
{
     cout << "First constructor" << endl;
     this->result = result;
     
     this->srChange = srChange;
     this->endRank = endRank;
     this->groupSize = groupSize;
     
     this->map = map;
     
     this->heroes = heroes;
     
     teamSR  = 0;
     enemySR = 0;
     this->save();
}

Saver::Saver(char result, double srChange, int endRank, string map, int groupSize, vector<string> heroes, int teamSR, int enemySR)
{
     cout << "Second breakfast constructor" << endl;
     this->result = result  
