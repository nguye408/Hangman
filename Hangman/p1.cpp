// Huy Vu
// p1.cpp
// Purpose: Let user play Hangman game
// Input: file of words p1input.dat provided by instructor
//        letter input from user
// Output: statistic, alphabet, secret word
//         body part of the hangman
//         final result of the game

#include "hangman.h"

using namespace std;

int main()
{
  // create object playGame
  Hangman playGame;
  
  char letter;           // letter input from user
  bool gameOver = false; // check if game over
  bool gameWon = false;  // check if game won
  string filename;       // name of a file containing a list of words
  string answer;         // answer from user to play game or nor
  
  cout << endl << endl;
  cout << "~~~~~~Welcome to the Hangman game~~~~~~" << endl << endl;
  cout << " In this game, you have to guess the secret word.\n"
	   << " A hangman will display on the noose if you give \n"
	   << " wrong guesses 7 times.\n"
       << " The game will end when all words have been used \n"
       << " or you chooses to quit.";
  cout << endl << endl;
  cout << "Do you want to play (yes or no)? ";
  cin >> answer;
  if (answer == "yes"){
	cout << endl;
	cout << "Enter the name of a file containing a list of words: ";
	cin >> filename;
	
	// check if the file is available or not
	if(!playGame.initializeFile(filename)){
	  cout << "file problem..exiting" << endl;
	  return 0;
	}else{
	  cout << "file loaded OK" << endl << endl;
	}
	
	// display statistics of the game
	playGame.displayStatistics();
	
	// repeat until the words run out or player wants to quit
	while(playGame.newWord()){
	  playGame.displayGame(); // display hangman body, word, letters
	  gameOver = false;
	  gameWon = false;
	  
	  // ask for the guessed letters
	  while (!gameOver){
		cout << "What letter? ";
		cin >> letter;
		playGame.guess(toupper(letter), gameOver, gameWon);
		playGame.displayGame();
	  }
	  
	  // show the secret word after failing 7 times
	  playGame.revealWord();
	  
	  // display a message when winning
	  if (gameWon){
		cout << "You won!" << endl;
	  }
	  
	  // update the statistic of the game
	  cout << endl << endl;
	  playGame.displayStatistics();
	  
	  // ask if player wants to play again or not
	  cout << endl << endl;
	  cout << "Do you want to play again (yes or no)? ";
	  cin >> answer;
	  
	  if (answer != "yes"){
		cout << endl << endl;
		cout << endl << "~~~~~~Goodbye~~~~~~" << endl << endl;
		return 0;
	  }
	}
	
	// notice the user that words run out
	if(!playGame.newWord()){
	  cout << endl << endl;
	  cout << "Sorry, there is no more words to play" << endl;
	  cout << endl << endl;
	  cout << "~~~~~~Goodbye~~~~~~" << endl << endl;
	}
  }else{
	cout << endl << endl;
	cout << "~~~~~~Goodbye~~~~~~" << endl << endl;
  }
  return 0 ;
}

  
  
