//Kareem Hussein

#ifndef PRONOUNCE_
#define PRONOUNCE_

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

class Pronounce
{
	public:
		/**Parameterized Constructor**/
		Pronounce(string word);
		
		/**
		@param word indicating the word found in the dictionary
		@return a string of the pronunciation found in the dictionary
		**/
		string getPronunciation(const string word);
		
		/**
		@param word indicating the word found in the dictionary
		@param pron indicating the pronunication of that word
		@post prints out all words with identical pronunication
		**/
		void getIdentical(const string word, const string pron);
		
		/**
		@param word indicating the word found in the dictionary
		@param pron indicating the pronunication of that word
		@post prints out all words with just one phoneme replaced
		**/
		void replacePhoneme(const string word, const string pron);
		
		/**
		@param word indicating the word found in the dictionary
		@param pron indicating the pronunication of that word
		@post prints out all words with just one phoneme added
		**/
		void addPhoneme(const string word, const string pron);
		
		/**
		@param word indicating the word found in the dictionary
		@param pron indicating the pronunication of that word
		@post prints out all words with just one phoneme removed
		**/
		void removePhoneme(const string word, const string pron);
	
	private:
		string word_;		//data member
		
		/**
		@param string indicating the entire line (both word and pronunication)
		@param before indicating everything before first space
		@param after indicating everything after first space
		@post before and after are updated containing halves of the string
			  before and after are passed by reference
		**/
		void splitOnSpace(string s, string& before, string& after);
};

#endif