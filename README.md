# Dictionary

This project behaves as a linguistic application that utilizes the CMU Pronouncing Dictionary (cmudict.0.7a) to report words with similar pronunciations. Linguists define a phoneme as the smallest unit of speech distinguishing one word (or word element) from another, as the element p in “tap,” which separates that word from “tab,” “tag,” and “tan.” In this project, cmudict.0.7 is the dictionary file that contains an extensive list of terms with its corresponding phoneme break-up for each word. When compiling and then running pronounce.cpp, a message prompt appears on the terminal asking the user to enter a word (user input is case-insensitive) and then proceeds to print words with slightly altered pronunciations. Here is an example: 

	Enter the word: Program

	Pronunciation    : P R OW1 G R AE2 M

	Identical        : PROGRAMME

	Replace Phoneme  :

	Add Phoneme      : PROGRAM'S PROGRAMMED PROGRAMMER PROGRAMS PROGRAMS'

	Remove Phoneme   :

Here is what each criteria means in depth

	Pronunciation : the pronunciation of the word W (as given in the dictionary),

	Identical : other words from the dictionary with the same pronunciation as W,

	Add phoneme : words that can be obtained from W by adding one phoneme,

	Remove phoneme : words that can be obtained from W by removing one phoneme,

	Replace phoneme : words that can be obtained from W by replacing one phoneme

Understanding phonemes is a crucial factor towards reading comprehension. In this project specifically, phonemic isolation is emphasized to help those (mainly children) to recognize familiar words and decode words they have never seen before, thus improving spelling and retention of complex sounding words.


# Running
There are three components you should make sure you have installed:

1. g++ compiler

2. a functioning terminal application

3. a good plain text editor (Gedit, Emacs, Vim, or Sublime Text) to write programs

Simply type on the terminal line:

	g++ -o pronounce pronounce.cpp

Then, run the executable file 
	
	./pronounce

And type in any word that is found in the CMU pronouncing dictionary!

