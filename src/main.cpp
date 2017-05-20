#include <iostream>
//#include "/SaveAndLoad/load.h"
#include "SaveAndLoad/save.h"

#include <fstream>
#include <string>
#include <locale>
#include <vector>


using namespace std;

int main()
{
     //Make and run window until exit run me daddy
     
     char result = 'w';
     int srChange = 28;
     int endRank = 3800;
     string map = "Numbani";
     int groupSize = 1;
     vector<string> heroes;
     //heroes[0] = "Genji";
     //heroes[1] = "NULL";
     //heroes[2] = "null";
     
     Saver game1;
     Saver game(result, srChange, endRank, map, groupSize, heroes);
     cout << "Games made" << endl;
     
     
     
     
     
     
     
     
     
     cout << "Build successful" << endl;
     return 0;
}
