#include <iostream>

// To import sleep function frome ither windows or linux we use an if statement to choose wich one is appropriate.
#ifdef _WIN64
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <stdlib.h>// imports cls
#include "BasicTimer.h"
#include "BasicFunctions.h"
using namespace std;
BasicTimer::BasicTimer(){
  
}



// when time runs out quit
void BasicTimer::WhenTimerRunsOut(){
  if (seconds < 1){
    
  if (timerAppEnd == true){
      cout << "timer over!!!\n";
    cout << "press 1 to reset or 2 to quit\n";

     cin >> timerMenuselect;
  while (timerMenuselect < 1 or timerMenuselect > 2) {
		
    cout << "that is not a valid input\n";
		cin >> timerMenuselect;}

  ClearScreen();
  switch (timerMenuselect) {
    case 1: {
      StartTimer();
    }
    case 2: {
      ExitToMain();
    }
   }// end of switch
   
  }
  else {
  // The program will either quit of unpause depending on if its a a stand alone app or part of somthing larger that needed a temporary pause.
    }
  }
  else
  {
    RemoveTime();
  }
}

void BasicTimer::RemoveTime(){
 seconds--;
  
  if (broadcastSecondsLeft == true){
    cout <<endl << seconds << " seconds left.";
  }
  
  // 1000 Miliseconds = 1 second.
  Sleep(1000); // Sleep for windows has the s capitalized, for linux it has it lowercase.
  WhenTimerRunsOut();
}

void BasicTimer::StartTimer(){
  system("clear");
  cout << "Enter the number of seconds\nPS dont type any letters or else the program will die!\n";
  
  cin >> seconds;
  ClearScreen();
  // after inputing the number of seconds start the timer by starting remove time.
  RemoveTime();
}

void BasicTimer::TimerMenu(){
  ClearScreen();
  cout << "this is a primetive timer set for a minute.\n";
  cout << "press 1 to start the timer and 2 to quit.\n\n\n";

  cin >> timerMenuselect;
  while (timerMenuselect < 1 or timerMenuselect > 2) {
		
    cout << "that is not a valid input\n";
		cin >> timerMenuselect;}

  ClearScreen();
  switch (timerMenuselect) {
    case 1: {
      StartTimer();
    }
    case 2: {
      ExitToMain();
    }
  }
  
  
}
