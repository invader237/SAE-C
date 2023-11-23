#ifndef wind_H
#define wind_H


//======================//
//=hidden Number header=//
//======================//

int hiddenNumber();
int isInteger(char input[]);

//----------------------//

//======================//
//===Mystery Sequence===//
//======================//
int mysterySequence();
int randGenerator();
int* sequenceGenerator();
int computeNextTerm();
//----------------------//

//======================//
//==Master Mind Header==//
//======================//

int mastermind();
int checkPosCorrect(char *user, char *vowelListe);
int checkPosIncorrect(char *user, char *vowelListe);
char generateOneRandomVowel();
char* generateVowelList();
int verifVowel(char caracter);

//----------------------//

void writeIfGreater(int gameNumber, int newScore);

#endif
