#include "iostream"
#include "TitleScreen.h"
#include "BasicFunctions.h"// Quit and ClearScreen functions.
#include "StartGames.h"// Voids for starting all the diffrent games.
using namespace std;
void Menu(){
  ClearScreen();
  int AppSelect;
  cout << "Choose wich app you want to play by entering a number.\n\n\n0 Exits the game,\n1 plays Lucky Survival,\n2 plays Monster Encounter,\n3 starts a Primitive Timer.\n\n";
  cin >> AppSelect;

  while (AppSelect < 0 or AppSelect > 3) {
		
    cout << "That is not a valid input.\n";
		cin >> AppSelect;}

  //ClearScreen();
  switch (AppSelect) {
    
    case 0: {
      QuitGame();
    }
    case 1: {
      StartLuckySurvival();      
    }
    case 2: {
      StartMonsterEncounter();
    }
    case 3: {
      StartBasicTimer();
    }
  }
}