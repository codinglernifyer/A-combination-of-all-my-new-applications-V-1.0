#include <string>
#include <stdlib.h> //Imports srand and rand

class LuckySurvival{
private:

public:


// variables
int menuSelect;
// health variables
int maxHealth = 15; 
int Health = 15; 
int minHealth = 1;

int startingHealth;
int startingMaxHealth;
// random number genorator variables
const int UPPER_LIMIT = 6, LOWER_LIMIT = -5;// the upper number it can be is 5 at deafault and the lowest number it can genorate is -5 at deafault.
int target = (rand() %(UPPER_LIMIT - LOWER_LIMIT) + LOWER_LIMIT);
// daycounter
int days = 0;

LuckySurvival();
// voids

void LS_StartOrRestart();
void LS_Quit();
void LS_RollDice();
void LS_ActionsWhenDiceRolled();
void LS_Options();

};