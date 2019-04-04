//Kareem Hussein

#include "Pronounce.hpp"
using namespace std;

/**Parameterized Constructor**/
Pronounce::Pronounce(string word):word_(word)
{
}

/**
 @param word indicating the word found in the dictionary
 @return a string of the pronunciation found in the dictionary
**/
string Pronounce::getPronunciation(const string word)
{
	//Open the file and read it
	ifstream input("cmudict.0.7a");
	//If the file cannot be read, then print an error
	if (input.fail())
	{
		cerr << "File cannot be opened" << endl;
		exit(1);
	}
	
	//Declare a string and set found to false
	string line;
	string before = "";
	string after = "";
	
	bool found = false;
	//While the file is being read into str
	while (getline(input, line))
	{
		splitOnSpace(line, before, after);
		//If the word the user entered is matched with another word in the file
		if (word == before)
		{
			//Set found to true
			found = true;
			break;
		}
	}
	
	//If true, then return the str (afterSpace)
	if (found)
	{
		return after;
	}
	
	//If false, then return "Not found"
	else
	{
		return "Not found";
	}
	
	//Close the file
	input.close();
}

/**
 @param word indicating the word found in the dictionary
 @param pron indicating the pronunication of that word
 @post prints out all words with identical pronunication
**/
void Pronounce::getIdentical(const string word, const string pron)
{
	//Store the dictionary word and pronunciation
	string dict_word = "";
	string dict_pron = "";
	
	//Read the file and create a string line
	ifstream input("cmudict.0.7a");
	string line;
	
	//While getting every line in input
	while (getline(input,line))
	{
		//Split the line (beforeSpace and afterSpace) into dict_word (beforeSpace) and dict_pron (afterSpace)
		splitOnSpace(line, dict_word, dict_pron);
		
		//If the user input pronunciation is equal to the dictionary pronunciation
		//If the user input word is not equal to the dictionary word (to avoid repetition)
		if (pron == dict_pron && dict_word != word)
		{
			//Print out the dictionary word
			//This function is trying to find the dictionary word with the same pronunciation as the user input word
			cout << dict_word << " ";
		}
	}

	input.close();
}

/**
 @param word indicating the word found in the dictionary
 @param pron indicating the pronunication of that word
 @post prints out all words with just one phoneme replaced
**/
void Pronounce::replacePhoneme(const string word, const string pron)
{
	//Create empty strings for the dictionary word pronunciation (to start comparisons)
	string before = "";
	string after = "";
	//Create empty strings for the user input word pronunciation (to start comparisons)
	string before1 = "";
	string after1 = "";
	//Create string replace_p to store the actual dictionary word before any splitting begins
	string replace_p;
	
	//Read a file and create a string line
	ifstream input("cmudict.0.7a");
	string line;
	int amount = 0;		//Declare integer amount
	
	//While getting every line in input
	while(getline(input, line))
	{
		//Split on the line and store the word in "before" and the pronunciation in "after"
		splitOnSpace(line, before, after);
		//In order to see how many times to actually split, count the number of spaces
		int size_dictpron = after.length();
		int size_pron = pron.length();
		int pron_spaces = 0; //Original
		int dict_spaces = 0; //Dictionary
		//For loop to determine the number of spaces in the user input pronunciation
		for(int i = 0; i < size_pron; i++)
		{
			if(pron[i] == ' ')
			{
				pron_spaces++;
			}
		}
		//For loop to determine the number of spaces in the dictionary pronunciation
		for(int i = 0; i < size_dictpron; i++)
		{
			if(after[i] == ' ')
			{
				dict_spaces++;
			}
		}
		
		//Store before(contains the original dictionary word) in replace_p
		replace_p = before;
		//Split to get the first phoneme of the dictionary pronunciaton
		splitOnSpace(after, before, after);
		splitOnSpace(after, before, after);		//Split again because the first phoneme contains an extra space
		//Split to get the first phoneme of the user input pronunciation
		splitOnSpace(pron, before1, after1);
		splitOnSpace(after1, before1, after1);
		//Keep track of how many phonemes are different/were replaced
		amount = 0;
		
		//Make sure both phonemes are the same length
		//Each phoneme should have the same numbers of spaces inbetween
		if(pron_spaces == dict_spaces)
		{
			//Use a for loop to compare each phoneme
			for(int i = 0; i < dict_spaces; i++)
			{
				//If both phonemes are equal
				if(before == before1)
				{
					//Advance to the next phoneme
					splitOnSpace(after, before, after);
					splitOnSpace(after1, before1, after1);
				}
				
				//If both phonemes do not equal
				else if(before != before1)
				{
					//Increase the amount
					amount++;
					//Advance to the next phoneme
					splitOnSpace(after, before, after);
					splitOnSpace(after1, before1, after1);
					
					//If there are more than 2 phonemes that are different, leave the loop
					if(amount > 2)
					{
						break;
					}
				}
			}
		}
		
		//We have found a word with only one replaced phoneme
		if(amount == 1)
		{
			//Algorithm to ensure that the original word is formatted correctly with uppercases
			bool notgood = false;
			int size = replace_p.length();
			for(int i = 0; i < size ; i++)
			{
				if (!((replace_p[i] >= 'A') && (replace_p[i] <= 'Z') || (replace_p[i] == char((int)39))))
				{
					notgood = true;
				}
			}
			
			if(!notgood)
			{
				cout << replace_p << " ";
			}
		}
	}
	//Close the file stream
	input.close();
}

/**
 @param word indicating the word found in the dictionary
 @param pron indicating the pronunication of that word
 @post prints out all words with just one phoneme added
**/
void Pronounce::addPhoneme(const string word, const string pron)
{
	//Create empty strings for the dictionary word pronunciation (to start comparisons)
	string before = "";
	string after = "";
	//Create empty strings for the user input word pronunciation (to start comparisons)
	string before1 = "";
	string after1 = "";
	//Create string add_p to store the actual dictionary word before any splitting begins
	string add_p;
	
	//Read a file and create a string line
	ifstream input("cmudict.0.7a");
	string line;
	int amount = 0;
	
	//While getting every line in input
	while(getline(input, line))
	{
		//Split on the line and store the word in "before" and the pronunciation in "after"
		splitOnSpace(line, before, after);
		//In order to see how many times to actually split, count the number of spaces
		int size_dictpron = after.length();
		int size_pron = pron.length();
		int pron_spaces = 0; //Original
		int dict_spaces = 0; //Dictionary
		
		//For loop to determine the number of spaces in the user input pronunciation
		for(int i = 0; i < size_pron; i++)
		{
			if(pron[i] == ' ')
			{
				pron_spaces++;
			}
		}
		
		//For loop to determine the number of spaces in the dictionary pronunciation
		for(int i = 0; i < size_dictpron; i++)
		{
			if(after[i] == ' ')
			{
				dict_spaces++;
			}
		}
		
		//Store before(contains the original dictionary word) in add_p
		add_p = before;
		//Split to get the first phoneme of the dictionary pronunciaton
		splitOnSpace(after, before, after);
		splitOnSpace(after, before, after);		//Split again because the first phoneme contains an extra space
		//Split to get the first phoneme of the user input pronunciation
		splitOnSpace(pron, before1, after1);
		splitOnSpace(after1, before1, after1);
		//Keep track of how many phonemes are different/were replaced
		amount = 0;
		
		//Additional phoneme means a word in the dictionary will have one more space than user input word
		if(pron_spaces + 1 == dict_spaces)
		{
			//Use a for loop to compare phonemes
			for(int i = 0; i < dict_spaces; i++)
			{
				//If phonemes are equal
				if(before == before1)
				{
					//Proceed to next phoneme
					splitOnSpace(after, before, after);
					splitOnSpace(after1, before1, after1);
				}
				
				//If phonemes are not equal
				else if(before != before1)
				{
					//Increase amount
					amount++;
					//Proceed to next phoneme
					splitOnSpace(after, before, after);
					
					//Break out of loop if two or more phonemes are different
					if(amount > 2)
					{
						break;
					}
				}
			}
		}
		
		//If we have found one extra phoneme
		if(amount == 1)
		{
			//Algorithm to ensure that the original word is formatted correctly with uppercases
			bool notgood = false;
			int size = add_p.length();
			for(int i = 0; i < size ; i++)
			{
				if (!((add_p[i] >= 'A') && (add_p[i] <= 'Z') || (add_p[i] == char((int)39))))
				{
					notgood = true;
				}
			}
			
			if(!notgood)
			{
				cout << add_p << " ";
			}
		}
	}
	
	//Close stream
	input.close();
}

/**
 @param word indicating the word found in the dictionary
 @param pron indicating the pronunication of that word
 @post prints out all words with just one phoneme removed
**/
void Pronounce::removePhoneme(const string word, const string pron)
{
	//Create empty strings for the dictionary word pronunciation (to start comparisons)
	string before = "";
	string after = "";
	//Create empty strings for the user input word pronunciation (to start comparisons)
	string before1 = "";
	string after1 = "";
	//Create string remove_p to store the actual dictionary word before any splitting begins
	string remove_p;
	
	//Read a file and create a string line
	ifstream input("cmudict.0.7a");
	string line;
	int amount = 0;
	
	//While getting every line in input
	while(getline(input, line))
	{
		//Split on the line and store the word in "before" and the pronunciation in "after"
		splitOnSpace(line, before, after);
		
		//In order to see how many times to actually split, count the number of spaces
		int size_dictpron = after.length();
		int size_pron = pron.length();
		int pron_spaces = 0; //Original
		int dict_spaces = 0; //Dictionary
		
		//For loop to determine the number of spaces in the user input pronunciation
		for(int i = 0; i < size_pron; i++)
		{
			if(pron[i] == ' ')
			{
				pron_spaces++;
			}
		}
		
		//For loop to determine the number of spaces in the dictionary pronunciation
		for(int i = 0; i < size_dictpron; i++)
		{
			if(after[i] == ' ')
			{
				dict_spaces++;
			}
		}
		
		//Store before(contains the original dictionary word) in remove_p
		remove_p = before;
		//Split to get the first phoneme of the dictionary pronunciaton
		splitOnSpace(after, before, after);
		splitOnSpace(after, before, after);			//Split again because the first phoneme contains an extra space
		//Split to get the first phoneme of the user input pronunciation
		splitOnSpace(pron, before1, after1);
		splitOnSpace(after1, before1, after1);
		//Keep track of how many phonemes are different/were replaced
		amount = 0;
		 
		//Removing phoneme so the dictionary word must be one space less than user input word
		if(pron_spaces - 1 == dict_spaces)
		{
			//Loop through both words
			for(int i = 0; i < pron_spaces; i++)
			{
				//If both phonemes are equal
				if(before == before1)
				{
					//Proceed to next phoneme
					splitOnSpace(after, before, after);
					splitOnSpace(after1, before1, after1);
				}
				
				//If both phonemes are not equal
				else if(before != before1)
				{
					//Increase amount
					amount++;
					splitOnSpace(after1, before1, after1);
					
					//If both words differ in more than 2 phonemes, break out of the loop
					if(amount > 2)
					{
						break;
					}
				}
			}
		}
		
		before = "";
		after = "";
		
		//If there is one phoneme difference
		if(amount == 1)
		{
			//Algorithm to ensure that the original word is formatted correctly with uppercases
			bool notgood = false;
			int size = remove_p.length();
			for(int i = 0; i < size ; i++)
			{
				if (!((remove_p[i] >= 'A') && (remove_p[i] <= 'Z') || (remove_p[i] == char((int)39))))
				{
					notgood = true;
				}
			}
			
			if(!notgood)
			{
				cout << remove_p << " ";
			}
		}
	}
	
	//Close the stream
	input.close();
}

//---------------------------------------------------------------------------
/*PRIVATE MEMBER FUNCTION, ensures that client does not tamper with the
functionality of splitting the word and its pronunciation*/

/**
 @param string indicating the entire line (both word and pronunication)
 @param before indicating everything before first space
 @param after indicating everything after first space
 @post before and after are updated containing halves of the string
       before and after are passed by reference
**/
//This private member function mimics the functionality of Python's split function
void Pronounce::splitOnSpace(string s, string& before, string& after)
{
	before = "";			//reset the strings
	after = "";				//reset the strings
	//accumulate before space
	int i = 0;
	while (i < s.size() && not isspace(s[i]))
	{
		before += s[i];
		i++;
	}
	//skip the space
	i++;
	//accumulate after space
	while (i < s.size())
	{
		after += s[i];
		i++;
	}
}
