// Huy Vu
// hangman.h


#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

#ifndef HANGMAN_H
#define HANGMAN_H

using namespace std;

class Hangman
{
 public:
  Hangman();
  // constructor
  
  bool initializeFile(string filename);
  // initialize the list of words from file, return false if it is bad
  
  void displayStatistics();
  // display win/loses/number of words read from file and available words
  
  bool newWord();
  // chooses new word from list of words randomly, return false if no
  // more words available
  
  void displayGame();
  // display hangman body, word, letters still available

  bool guess(char letter, bool& done, bool& won);
  // processes the user's guess
  
  void revealWord();
  // displays the word with all letters
  
 private:
  static const int LIST_SIZE = 100;
  static const int BODY_SIZE = 9;
  static const int ALPHA_SIZE = 26;
  static const int MAX_BAD_GUESSES = 7;
  static const int HEAD = 7;
  static const int NECK = 6;
  static const int LT_ARM = 5;
  static const int RT_ARM = 4;
  static const int TORSO = 3;
  static const int LT_LEG = 2;
  static const int RT_LEG = 1;
  
  struct WordList{
	string word;
	bool used;
  };
  struct BodyPart{
	string firstLine;
	string secondLine;
	string thirdLine;
	bool displaySecond;
	bool displayThird;
  };
  
  WordList list[LIST_SIZE];       // creating the list of words from file
  BodyPart body[BODY_SIZE];       // creating the list of different body parts
  char alphabet[ALPHA_SIZE];      // creating the list of alphabet
  string correctWord;             // word that need to guess
  string letters;                 // alphabet
  int wordLength;                 // length of secret word
  int remainingLetters;           // remaining letters that available to use
  int turn;                       // number of turns to guess
  int wins;                       // number of wins 
  int losses;                     // number of losses
  int totalWords;                 // total words from a file
  int availableWords;             // available words to use
};

#endif 
