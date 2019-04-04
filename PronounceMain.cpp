//Kareem Hussein

#include <iostream>
#include "Pronounce.hpp"
using namespace std;

int main()
{
	//First, open a stream to read the dictionary file
	ifstream input("cmudict.0.7a");
	//If unable to read file, prompt a message
	if (input.fail())
	{
		cerr << "File cannot be opened" << endl;
		exit (1);
	}
	
	//Declare a string "word" to store the user input word
	string user_word;
	cout << "Enter the word:";
	cin >> user_word;
	cout << endl;
	
	//What user entered is case-insensitive (lowercase or uppercase)
	//Algorithm to convert lowercase to all uppercase
	//The file we are reading contains all uppercase letters
	int size = user_word.length();
	for (int i = 0; i < size; i++)
	{
		char c = user_word[i];
		if ((int)c >= 97 && (int)c <= 122)  //if the current character is lowercase
		{
			//Convert to uppercase
			//A lowercase ascii character is 32 decimals away from its uppercase equivalent
			c = (c - 32);
			user_word[i] = c;		//Replace the position of the lowercase character with the converted uppercase character back
		}
	}
	
	//We are done assessing precautionary measures (opening a file, case sensitive words)
	//Instantiate an object myWord of datatype Pronounce and initialize it with the user input word
	Pronounce myWord(user_word);
	
	//Make sure the word is actually in the dictionary file
	string dictionary_word;
	bool found = false;
	while (input >> dictionary_word)	//While we read the word
	{
		if (dictionary_word == user_word)	//If the a word in the dictionary matches with user_input word, we found the word!
		{
			found = true;					//Set found to true
			break;							//Break out of while loop since we found the word
		}
	}
	
	if(found)
	{
		//Use a function getPronunciation() and store the current pronunciation in pron to use for later
		string pron;
		pron = myWord.getPronunciation(user_word);
		cout << "Pronunciation    :" << pron << endl;
		cout << "Identical        : ";
		myWord.getIdentical(user_word, pron);
		cout << endl;
		cout << "Replace Phoneme  : ";
		myWord.replacePhoneme(user_word, pron);
		cout << endl;
		cout << "Add Phoneme      : ";
		myWord.addPhoneme(user_word, pron);
		cout << endl;
		cout << "Remove Phoneme   : ";
		myWord.removePhoneme(user_word, pron);
		cout << endl;
	}
	
	else
	{
		cout << "Not found" << endl;
	}
	
	return 0;
}