#include <iostream>
#include "SaveAndLoad/load.cpp"
#include "SaveAndLoad/save.cpp"

#include <fstream>
#include <string>
#include <locale>
#include <vector>


using namespace std;

int main()
{
     //Make and run window until exit run me daddy
     
     string result = "win";
     int srChange = 28;
     int endRank = 3800;
     string map = "Numbani";
     int groupSize = 1;
     vector<string> heroes;
     heroes.push_back("GEnJI");
     heroes.push_back("nuLl");
     heroes.push_back("NULL");
     
     //Saver game1('w',2,2,"test",1,heroes);
     //Saver saveGame(result, srChange, endRank, map, groupSize, heroes);
     cout << "Games made" << endl;
     
     Loader game1(2);
     
     if (game1.loaded()) {
          cout << "game loaded: " << game1.loaded() << endl;
          game1.print();
     }
     
     
     
     cout << "Build successful" << endl;
     return 0;
}
