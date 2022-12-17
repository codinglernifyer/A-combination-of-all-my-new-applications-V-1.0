#include <stdlib.h>// Imports clear screen functions.
#include "iostream"
#include "BasicFunctions.h"
#include "TitleScreen.h"
void ClearScreen(){
 //system("clear");// For lunix.
 system("CLS");// For windows.
 //std::cout << "\033[2J\033[0;0H";//A hex code to clear the screen on replit.
}

void ExitToMain(){
 Menu();
}

int QuitGame(){
	exit(0);
}