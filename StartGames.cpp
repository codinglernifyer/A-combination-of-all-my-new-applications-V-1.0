#include "StartGames.h"
// This contains a bunch of voids that will allow you to start the diffrent apps inside this mega app. These voids will set all the valuse to the right numbers and run the starting voids.

#include "LuckySurvival.h"
void StartLuckySurvival(){
  LuckySurvival LS; // Creates a round of lucky survival.

  LS.startingHealth = 20;// Health you start with.
  LS.startingMaxHealth = 20;// Them max amount of health you can have at once.

  LS.LS_StartOrRestart();// This is the void that starts the game.
}



#include "MonsterEncounter.h"
void StartMonsterEncounter(){
// Basic variables for the game.
MonsterEncounter MB; // Creates a Monster Encounter object that you can edit the attributes of.

MB.secondsGameIsPaused = 4;// Chooses how many seconds the game is paused after every player move.
  
MB.monsterName = "monster";// Ghange the name of the monster here.

MB.startingMonsterHealth = 30;// This is the ammount of health the monster will start with when you start a new game.

MB.startingPlayerHealth = 30;// This is the ammount of health the player will start with when you start a new game.

MB.maxMoves = 20; // The max ammount of moves before game over will be set here.
	

// Monster move values that controll the power of the monsters diffrent moves.
MB.monsterMove1dmgval = 10; // Damage the monster dose to the player with its first move. Default is 10.
	
MB.monsterMove2regenval = 10; // Health the monster gains using its second move. Default is 10.

// The third monster move dose two things at once.
MB.monsterMove3regenval = 4; // Health the monster gains using its third move. Default is 4.
MB.monsterMove3dmgval = 4; // Damage the monster dose to the player with its third move. Default is 4.

  
// Player move values that controll the power of the players diffrent moves.
MB.playerMove1dmgval = 10; // Damage the player dose to the monster with its first move. Default is 10.
MB.playerMove2regenval = 10; // Health the player gains using its second move. Default is 10.
	
// The third player move dose two things at once.
MB.playerMove3regenval = 4; // Health the player gains using its third move. Default is 4.
MB.playerMove3dmgval = 4; // Damage the player dose to the monster with its third move. Default is 4.
	
	
  MB.MonsterFighterTitleScreen();// This is the void that starts the game.

}



#include "BasicTimer.h"
void StartBasicTimer(){
  BasicTimer t;// Create a basic timer object.
  
  t.timerAppEnd = true;// This bool decides if when the timer runs out weather you want to allow the player to quit or play again asuming the timer program is in the form of a stand alone app with a title screen (that would mean it is set to true), or if you want the app to stop imidietly and not have an ending screen (that would mean it is set to false), this would be usefull for a timer that is a part of a larger app.
  
  
  t.broadcastSecondsLeft = true;// Choose if you want to make the timer broadcast the amount of time left.
  
  t.TimerMenu();// Timer menu starts the game.
}
