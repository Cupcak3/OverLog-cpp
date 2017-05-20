#ifndef SAVER_CPP
#define SAVER_CPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Saver
{
     private:
     void save()
     {
          
          //Make all letters lowercase in all words
          for (unsigned i = 0; result[i]; ++i) this->result[i] = tolower(result[i]);
          for (unsigned i = 0; map[i]; ++i)   this->map[i]    = tolower(map[i]);
          for (unsigned i = 0; i < heroes.size(); ++i)
          {
               string name = heroes.at(i);
               for (unsigned j = 0; name[j]; ++j) name[j] = tolower(name[j]);
               heroes.at(i) = name;
          }
          
          
          //Save to file
          fstream file;
          
          file.open("exec//stats.txt", fstream::app);
          file << this->result << " " << srChange << " " << endRank << " " << this->map << " ";
          for(unsigned i = 0; i < heroes.size(); ++i)
          {
               file << this->heroes.at(i) << " ";
          }
          file << teamSR << " " << enemySR << endl;
          
          file.close();
     }
     
     string result, map;
     int srChange, endRank, groupSize, teamSR, enemySR;
     vector<string> heroes;
     
     public:
     Saver(string result, int srChange, int endRank, string map, int groupSize, vector<string> heroes)
     {
          this->result = result;
          
          this->srChange = srChange;
          this->endRank = endRank;
          this->groupSize = groupSize;
          
          this->map = map;
          
          this->heroes = heroes;
          
          teamSR  = 0;
          enemySR = 0;
          save();
     }
     Saver(string result, int srChange, int endRank, string map, int groupSize, vector<string> heroes, int teamSR, int enemySR)
     {
          this->result = result;
          
          this->srChange = srChange;
          this->endRank = endRank;
          this->groupSize = groupSize;
          
          this->map = map;
          
          this->heroes = heroes;
          
          this->teamSR = teamSR;
          this->enemySR = enemySR;
          save();
     }
     
     
};
#endif
