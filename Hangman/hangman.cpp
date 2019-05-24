// Huy Vu
// hangman.cpp

#include "hangman.h"

Hangman::Hangman()
{
  wins = 0;
  losses = 0;
  totalWords = 0;
  availableWords = 0;
  srand(time(0));
  body[0].firstLine = "    ----\n";
  body[1].firstLine = "    |  |\n";
  body[2].firstLine = "       |\n";
  body[2].secondLine = "    O  |\n";
  body[3].firstLine = "       |\n";
  body[3].secondLine = "    |  |\n";
  body[4].firstLine = "       |\n";
  body[4].secondLine = "   -|  |\n";
  body[4].thirdLine = "   -|- |\n";
  body[5].firstLine = "       |\n";
  body[5].secondLine = "    |  |\n";
  body[6].firstLine = "       |\n";
  body[6].secondLine = "   /   |\n";
  body[6].thirdLine = "   / \\ |\n";
  body[7].firstLine = "       |\n";
  body[8].firstLine = "_______|___\n";
}

bool Hangman::initializeFile(string filename)
{
  ifstream inFile;

  inFile.open(filename);
  
  if (inFile.fail())
	return false;
  
  while (inFile >> list[totalWords].word){
	list[totalWords].used = false;			
	totalWords++;
	availableWords++;
  }		 
  
  inFile.close();
  
  return true;
}

void Hangman::displayStatistics()
{
  cout << "Total words: " << totalWords << endl;
  cout << "Words still available: " << availableWords << endl;
  cout << "Wins: " << wins << endl;
  cout << "Looses: " << losses << endl;
}

bool Hangman::newWord()
{
  int newIndex;
  if(availableWords == 0)
	return false;
  do{
	newIndex = rand() % totalWords;
  }while(list[newIndex].used == true);
  list[newIndex].used = true;
  correctWord = list[newIndex].word;
  wordLength = correctWord.length();
  remainingLetters = wordLength;
  
  for (int i = 0; i < wordLength; i++)
	letters[i] = '_';
  turn = MAX_BAD_GUESSES;
  availableWords--;

  for (int i = 0; i < BODY_SIZE; i++){
	body[i].displaySecond = false;
	body[i].displayThird = false;
  }
  
  for (int i = 0; i < ALPHA_SIZE; i++)
	alphabet[i] = 65 + i;
  return true;
}

void Hangman::displayGame()
{
  for (int i = 0; i < BODY_SIZE; i++){
	if(body[i].displaySecond == false && body[i].displayThird == false)
	  cout << body[i].firstLine;
	if(body[i].displaySecond == true && body[i].displayThird == false)
	  cout << body[i].secondLine;
	if(body[i].displaySecond == false && body[i].displayThird == true)
	  cout << body[i].thirdLine;
  }
  
  cout << endl << endl;
  for (int i = 0; i < wordLength; i++)
	cout << letters[i] << "   ";
  cout << endl << endl;
  for (int i = 0; i < ALPHA_SIZE; i++)
	cout << alphabet[i] << " ";
  cout << endl << endl;
}

bool Hangman::guess(char letter, bool& done, bool& won)
{
  bool rightGuesses = false;
  for (int i = 0; i < ALPHA_SIZE; i++){
	if (alphabet[i] == letter){
	  alphabet[i] = 32;
	}
  }
  for (int i = 0; i < wordLength; i++){
	if (correctWord[i] == letter){
	  letters[i] = correctWord[i];
	  remainingLetters--;
	  rightGuesses = true;
	}
  }
  
  // display a single :body part" on the hangman's noose
  // when player gives wrong guesses.
  if (!rightGuesses){
	switch(turn){
	  case HEAD:
		  body[2].displaySecond = true;
		  break;
	  case NECK:
		  body[3].displaySecond = true;
		  break;
	  case LT_ARM:
		  body[4].displaySecond = true;
		  break;
	  case RT_ARM:
		  body[4].displaySecond = false;
		  body[4].displayThird = true;
		  break;
	  case TORSO:
		  body[5].displaySecond = true;
		  break;
	  case LT_LEG:
		  body[6].displaySecond = true;
		  break;
	  case RT_LEG:
		  body[6].displaySecond = false;
		  body[6].displayThird = true;
		  break;
	  }
	  turn--;
	}
  
  if (remainingLetters == 0){
	done = true;
	won = true;
	wins++;
  }
  if (turn == 0){
	done = true;
	losses++;
  }
  return true;
}

void Hangman::revealWord()
{
  cout <<  "Answer: " << correctWord << endl;
}
 
