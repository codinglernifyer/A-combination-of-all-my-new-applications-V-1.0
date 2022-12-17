#include <string>

class MonsterEncounter {
private:


public:

// strings for names
std::string monsterName = "monster";

// Int for time the game is paused every turn.
int secondsGameIsPaused = 4;

// ints for selecting diffrent player moves
int MoveSelect;


// health variables
int startingMonsterHealth = 20;
int MonsterHealth;

int startingPlayerHealth = 30;
int PlayerHealth;

// move counter variable to keep track of moves as it was found to be helpfull
int MoveCounter;

int maxMoves = 20; // this keeps track of the max amount of moves before game over
    
// these variables randomly select one of the monsters 3 attacks
    const int Attack_List_UPPER_LIMIT = 4, Attack_List_LOWER_LIMIT = 1;
    int MF_target = (rand() % (Attack_List_UPPER_LIMIT - Attack_List_LOWER_LIMIT) +
        Attack_List_LOWER_LIMIT);
    
// monster attack damage ints
// damage the monster dose to the player. default is 10
int monsterMove1dmgval = 10;
    
// health the monster regenorates. default is 10
int monsterMove2regenval = 10;
    
// health and dameg the monster regenorates and dose to player.
int monsterMove3regenval = 4;
int monsterMove3dmgval = 4;

// player attack damage ints
// damage the player dose to the monster. default is 10
int playerMove1dmgval = 10;

// health the player regenorates. default is 10
int playerMove2regenval = 10;
    
// health and damage the player regenorates along with doing damage to the monster.
int playerMove3regenval = 4;
int playerMove3dmgval = 4;


    MonsterEncounter(); // constructor

void MonsterFighterTitleScreen();// Title screen for the game.

void IsGameOverChecker();// Checks every turn if the player or monster has died, or if the player has used all there moves and will than give the acording ending to the situation.
    
void PlayerMoveOptions();// Allows the player to choose 1 of three moves.
    
void BrodcastStats();// Broadcasts the player and monsters health.
    
void BroadcastStatsAfterMonsterMove();// Broadcasts the player and monsters health after the monsters move, duh.

// Player moves.
void PlayerMove1();
void PlayerMove2();
void PlayerMove3();

void MonsterMove();// Genorates the random number bettween 1 and 3 that will decide the monsters attack.
    
void MonsterMoveSelect();// Depending on the number genorated in the MonsterMove() void it will run one of the moves. The moves are inbuilt into this void instead of being separate voids.
    
// These next three scripts work together to genorate a visual delay between the players last move and the monsters next move to make the change between the turns more obvious.
void pauseInGame();
    



};
#pragma once