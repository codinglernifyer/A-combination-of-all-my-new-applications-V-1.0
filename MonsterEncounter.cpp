#include "MonsterEncounter.h"
#include <iostream>
#include <stdlib.h> //Imports srand and rand along with the exit function
#include "BasicTimer.h"
#include "BasicFunctions.h"//Imports ClearScreen and QuitToMain.
//#include "BasicFunctions.h"
using namespace std;
MonsterEncounter::MonsterEncounter() {

}

void MonsterEncounter::MonsterFighterTitleScreen() {
    ClearScreen();
    MoveCounter = 0;
    MonsterHealth = startingMonsterHealth;
    PlayerHealth = startingPlayerHealth;
    cout << "You encounter a " << monsterName
        << " in the woods.\nYou must fight it or die at "
        "its hands!\n You have "
        << maxMoves << " moves, use them wisely\n\n";
    IsGameOverChecker();
}

void MonsterEncounter::IsGameOverChecker() {
    // check if the game should have ended by now before making player move

    // if player has lost all health than game over
    if (PlayerHealth < 1) {
        ClearScreen();// clears all the stats as they arent needed for the ending
        // if the players lost all its health than show the first game over screen
        cout << "You crumple up defeated by the beast. \nThe last thing you ever hear is its wild gleefull cackling.\nGame Over, 1 to restart and 2 to quit the game fully.\n\n";
        cin >> MoveSelect;
        while (MoveSelect < 1 or MoveSelect > 2) {

            cout << "Not a valid number.\n";
            cin >> MoveSelect;
        }


        switch (MoveSelect) {
        case 1: {
            MonsterFighterTitleScreen();
        }

        case 2: {
            ExitToMain();
        }
        }
        // end of switch
    }


    // if player has used up all moves than game over
    if (MoveCounter > maxMoves) {
        ClearScreen();// clears all the stats as they arent needed for the ending
        cout << "you collapse tired and beaten. \nEven if the " << monsterName << "'s dead, you havent any energy to see the light of day ever again\n Game Over, 1 to restart and 2 to quit the game fully\n\n";
        cin >> MoveSelect;
        switch (MoveSelect) {
        case 1: {
            MonsterFighterTitleScreen();
        }

        case 2: {
           ExitToMain();
        }
        }
        // end of switch


    }


    // if the player has beat the monster than the game is over
    if (MonsterHealth < 1)
    {
        // victory!
        ClearScreen();// clears all the stats as they arent needed.
        cout << "The " << monsterName << " crumbles to its feet and begins to melt\nfirst into blood,\nthan to dust\nand than as the dust begins to swirl into a small vicious tornado\nthe tornado starts to fade\nand after a little while, its all gone\n\n\n";
        cout << "youve survived\n game over, youve won\n\n\n";
        cout << "1 to restart and 2 to quit the game entirely\n";

        cin >> MoveSelect;
        while (MoveSelect < 1 or MoveSelect > 2) {

            cout << "Not a valid number\n";
            cin >> MoveSelect;
        }


        switch (MoveSelect) {
        case 1: {
            MonsterFighterTitleScreen();
        }

        case 2: {
            ExitToMain();
        }
        }
    }
    // if the game should not be over yet the else statement will allow it to continue 
    else {
        PlayerMoveOptions();
    }

}



void MonsterEncounter::PlayerMoveOptions() {
    // player move options 
    // just broadcasting stats so the player can see
    BroadcastStatsAfterMonsterMove();
    // showing move options
    MoveCounter++;
    cout << "Move " << MoveCounter << " of " << maxMoves << "\n";
    cout << " Your turn to move.\n\n";
    cout << " (Your Move Options)\n";
    cout << "1 To attack the " << monsterName << " (-" << playerMove1dmgval << " of its health)\n";
    cout << "2 To heal up (+" << playerMove2regenval << " of your health)\n";
    cout << "3 To do a bit of both (+" << playerMove3regenval << " of your health - " << playerMove3dmgval << " of the " << monsterName << "s)\n";
    cout << "And finally! 0 To quit!\n\n";
    // alowing players to select options

    cin >> MoveSelect;
    while (MoveSelect < 0 or MoveSelect > 3) {

        cout << "YOU HAVE NOT!! selected a number in between 0 and 3!!!\n";
        cin >> MoveSelect;
    }

    switch (MoveSelect) {
        // quit
    case 0: {
        ExitToMain();
    }
          // move 1
    case 1: {
        PlayerMove1();
    }
          // move 2
    case 2: {
        PlayerMove2();
    }
          // move 3
    case 3: {
        PlayerMove3();
    }
    }
}

void MonsterEncounter::BrodcastStats() {
    cout << "The " << monsterName << "'s health is " << MonsterHealth << ".\n";
    cout << "Your health is " << PlayerHealth << ".\n\n\n";

    pauseInGame();
}

void MonsterEncounter::BroadcastStatsAfterMonsterMove() {
    cout << "The " << monsterName << "'s health is now " << MonsterHealth << ".\n";
    cout << "Your health is now " << PlayerHealth << ".\n\n\n";
}

void MonsterEncounter::PlayerMove1() {
    // Subtract 10 monster health
    for (int i = 0; i < playerMove1dmgval; i++) {
        MonsterHealth--;
    }

    ClearScreen();
    cout << "The " << monsterName << " snarls as its wound\n";
    cout << "-10 of the " << monsterName << "s health\n\n";
    BrodcastStats();
    MonsterMove();
    IsGameOverChecker();
}

void MonsterEncounter::PlayerMove2() {
    // Add 10 player health
    for (int i = 0; i < playerMove2regenval; i++) {
        PlayerHealth++;
    }
    // after doing action do the monsters move and clear the previous move, than
    // let the player do another move
    ClearScreen();
    cout << "You feel a year younger with you spell.\n +10 health\n\n";
    BrodcastStats();
    MonsterMove();
    IsGameOverChecker();
}

void MonsterEncounter::PlayerMove3() {
    // Add 4 player health
    for (int i = 0; i < playerMove3regenval; i++) {
        PlayerHealth++;
    }
    // Subtract 4 monster health
    for (int i = 0; i < playerMove3dmgval; i++) {
        MonsterHealth--;
    }
    // after doing action do the monsters move and clear the previous move, than
    // let the player do another move
    ClearScreen();
    cout << "You chant a spell and start feel a little stronger. \nLooking the " << monsterName << " looks just a bit more shriviled and feeble\n\n";
    BrodcastStats();
    MonsterMove();
    IsGameOverChecker();
}
// triggers the monsters move
void MonsterEncounter::MonsterMove() {
    cout << "\nThe " << monsterName << " Makes Its Move!\n\n";
    // genorate the random attack of the monster
    MF_target = (rand() % (Attack_List_UPPER_LIMIT - Attack_List_LOWER_LIMIT) +
        Attack_List_LOWER_LIMIT);
    // selects the next move of the monster (note the move the monster makes is
    // selected the previous move)
    MonsterMoveSelect();
    // after making the move let the player decide there next move again
}


// randomly selects the monsters move like in Lucky Survival
void MonsterEncounter::MonsterMoveSelect() {
    // roll random attack for the monster
    srand(time(0)); // sets the seed for the random number
    // selects the moves randomly based on the target
    if (MF_target == 1) {
        cout << "The " << monsterName << " slashes at you with evil glee on its face!\n";
        cout << "-" << monsterMove1dmgval << " Of your health\n\n\n";
        for (int x = 0; x < monsterMove1dmgval; x++)
        {
            PlayerHealth--;
        }
    }

    if (MF_target == 2) {
        cout << "The " << monsterName << " seems stronger than it was a few seconds ago\n";
        cout << "+" << monsterMove2regenval << " monster health\n\n";
        for (int x = 0; x < monsterMove2regenval; x++)
        {
            MonsterHealth++;
        }
    }

    if (MF_target == 3) {
        cout << "The " << monsterName << " chants and all of a sudden you feel like youve witherd away a bit\n";
        cout << "+" << monsterMove3regenval << " monster health\n";
        cout << "-" << monsterMove3dmgval << " player health\n\n";
        // + 4 monster health
        for (int x = 0; x < monsterMove3regenval; x++)
        {
            MonsterHealth++;
        }
        // -4 player health
        for (int x = 0; x < monsterMove3dmgval; x++)
        {
            PlayerHealth--;
        }
    }




}

// a timer to make turns more clear
void MonsterEncounter::pauseInGame() {
  BasicTimer t;
  t.seconds = secondsGameIsPaused;
  t.broadcastSecondsLeft = false;//This is off so you dont have a countdown for every second that the game is paused.
  t.timerAppEnd = false;// This is off so it dosent broadcast the end of the timer app and take you to the timer app's title screen.
  t.RemoveTime();
  
}



