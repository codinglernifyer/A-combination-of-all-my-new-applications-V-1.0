#include <iostream>
#include <string>
#include <stdlib.h> //Imports srand and rand along with cls.
#include "LuckySurvival.h"
#include "BasicFunctions.h"//Imports ClearScreen and QuitToMain.
using namespace std;

LuckySurvival::LuckySurvival(){
  
}


// lucky survival voids
void LuckySurvival::LS_StartOrRestart(){
// states the value of some variables and broadcasts a title screen
  maxHealth = startingMaxHealth, Health = startingHealth;
  ClearScreen();
      cout << "Hello and welcome to lucky survival!\n\n";
      cout << "Every time you press the number 1 key,\nanother day will pass and you get a number between -5 and positive 5!\n\n";
      cout << "You will then gain or lose health depending on the number you get.\n";
      cout << "Surive as many days as possible!\n\n";
      cout << "1 to roll, 2 to restart, 0 to quit!\n\n";
      cout << "PS try not to click a letter or youll break everything. \n";
  // starts the cycle of the game
  LS_Options();
  
}

void LuckySurvival::LS_Quit(){
  ExitToMain();
}

void LuckySurvival::LS_RollDice(){
  target = (rand() %(UPPER_LIMIT - LOWER_LIMIT) + LOWER_LIMIT);
  ClearScreen();
      // displays dice number you rolled
      cout << "your dice roll is " << target << "\n";
      LS_ActionsWhenDiceRolled();
      // display dice roll
      //displaying health values
      cout << Health << " out of " << maxHealth << " health remaining \n \n";
      cout << "day " << days << "\n \n";
      cout << "1 to roll, 2 to restart, 0 to quit!\n\n";
      // addign to days
      days ++;
      
      // next move is done by resetting options void
      LS_Options ();
}

void LuckySurvival::LS_ActionsWhenDiceRolled() {
    
    // roll random dice
    srand(time(0)); //sets the seed for the random number
    // if dice is positive
    if (target == 1){
        cout << "+ 1 health\n";
        Health++;
      }
    if (target == 2){
        cout << "+ 2 health\n";
        Health++;
        Health++;
      }
    if (target == 3){
        cout << "+ 3 health\n";
        Health++;
        Health++;
        Health++;
      }
    if (target == 4){
        cout << "+ 4 health\n";
        Health++;
        Health++;
        Health++;
        Health++;
      }
    if (target == 5){
        cout << "+ 4 health\n";
        cout << "+ 1 max health\n";
        Health++;
        Health++;
        Health++;
        Health++;
        maxHealth++;
      }
    // if dice is zero
    if (target == 0){
        cout << "health value unchanged\n";
        Health = Health;
      }
    // if the dice is a negative number
    if (target == -1){
        cout << "- 1 health\n";
        Health--;
      }
    if (target == -2){
        cout << "- 2 health\n";
        Health--;
        Health--;   
      }
    if (target == -3){
        cout << "- 3 health\n";
        Health--;
        Health--;
        Health--;
      }
    if (target == -4){
        cout << "- 4 health\n"; 
        Health--;
        Health--;
        Health--;
        Health--;
      }
    if (target == -5){
        cout << "- 4 health\n";
        cout << "- 1 max health\n";
        Health--;
        Health--;
        Health--;
        Health--;
        maxHealth--;
      }
    // check to make sure max health dosent go above health
    if (maxHealth < Health){
      Health = maxHealth;
    }
    // game over if you lose all health
     if (Health < minHealth){
       cout << "\n\n\nyou lose!\n";
       cout << "you survived " << days << " days! \n\n";
       cout << "Press 2 to restart, press 0 to quit the game fully! \n";
       
       cin >> menuSelect;
  while (menuSelect < 0 or menuSelect > 2 or menuSelect == 1) {

    system("clear");
    
    
    cout << "Please sellect either 2 to restart Lucky Survival,\nor 0 to quit the game fully.\n";
		cin >> menuSelect;}

    switch (menuSelect) {
      case 2:{
        LS_StartOrRestart();
      }

      case 0:{
        LS_Quit();
      }
      
    }

    
	}
    
       
       
  }

void LuckySurvival::LS_Options (){
  // allows you to enter numers to trigger diffrent options
  // the diffrent options are diffrent voids
  cin >> menuSelect;
  while (menuSelect < 0 or menuSelect > 2) {
		
    cout << "Please select a number in between 0 and 2!\n";
		cin >> menuSelect;
    
	}
  
  
  // start of the switch
  switch (menuSelect) {

    // quit
    case 0: {
      LS_Quit();
    }
    
    // roll dice
    case 1: {
      LS_RollDice();
    }
    
    // reset
    case 2: {
      LS_StartOrRestart();
    }
    
    
  
    
  }
  // end of the switch command
  
}


// end of lucky survival voids


