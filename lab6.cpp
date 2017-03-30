/* File: lab6.cpp
*  Author: Matt Clinard
*  Description: This application evaluates an English sentence.
*  Last Date Changed: 11/21/2015
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;

const int MAX_WORD_CHARS = 16; // longest word = 15 chars
const int MAX_WORDS = 200;    // longest paragraph = 200 words
const int MAX_TOTAL_CHARACTERS = 3000; // 15 * 200
const int MAX_SENTENCES = 25;   // max number of sentences in paragraph
const int MAX_SENTENCE_CHARS = 200; // max number chars in a sentence;
const int NUM_TO_BE_VERBS = 5; 
const int NUM_OF_PUNC = 3; // number of punctuation characters
const char PUNCTUATION[] = { '!', '.', '?' }; // end of sentence punctuation
const char TO_BE_VERBS[NUM_TO_BE_VERBS][MAX_WORD_CHARS] = { "am", "are", "is", "was", "were" };
const char BE[] = "be";
const char TO[] = "to";
const int NUM_CONJUNCTIONS = 7;
// conjunctions with the commas
const char CONJUNCTIONS[NUM_CONJUNCTIONS][MAX_WORD_CHARS] = { "for", "and", "nor", "but", "or", "yet", "so" };

void openFile( ifstream&, string&);
void toLower(char[]);
int readSentences(char[]);
int tokenizeParagraph(char[], char[][MAX_WORD_CHARS]);
void removePunc(char [][MAX_WORD_CHARS], int);
int readToBe(char[][MAX_WORD_CHARS], int);

int main(){
	ifstream input; // input stream name
	string inputFile; // string to hold name of input file
	int characterCount; // used for number of characters in a paragraph
	double sentenceCount; // used for number of sentences in a paragraph
	double whitespace; // used for number of words in a paragraph
	double average; // used for average number of words per sentence
	int tobeCount = 0; // used for number of to be verbs in a paragraph
	char p[MAX_TOTAL_CHARACTERS]; // array for the paragraph
	char tp[MAX_WORDS][MAX_WORD_CHARS]; // two dimensional array for the tokenized paragraph


	openFile( input, inputFile);
	input.getline(p, MAX_TOTAL_CHARACTERS); // puts text from input file into p
	characterCount = strlen(p); // determines number of characters in a paragraph
	cout << "The number of characters in this paragraph is " << characterCount << ".\n";
	toLower(p); // lowercases all characters in a paragraph	
	sentenceCount = readSentences(p);
	whitespace = tokenizeParagraph(p, tp);
	cout << "The number of words in this paragraph is " << whitespace << ".\n";
	cout << "The number of sentences in this paragraph is " << sentenceCount << ".\n";
	average = (whitespace / sentenceCount); // average of number of words per sentence
	cout << cout.precision(1) << fixed; // sets precision for average number of words per sentence
	cout << "The average number of words per sentence is " << average << ".\n";
	removePunc(tp, whitespace);
	tobeCount = readToBe(tp, whitespace);
	cout << "The number of 'to be' verbs is " << tobeCount << ".\n";
	return(0);
}
/* openFile: Opens file given from user input and checks to see if file exists
*  Parameters:
*	   input: ifstream name
*	   inputFile: string name for the file
*  Precondition: A file name in inputFile
*  Postcondition: input and inputFile have been named. If file does not exist 
*  		  displays error message and exits the program. If file exists
* 		  is valid, and has been opened, returns file to main.
*/
void openFile( ifstream &input, string &inputFile ){
        cout << "Enter the input file name: ";
        cin >> inputFile;
        input.open(inputFile.c_str( ));
	
	if(input.fail( )){
		cout << "The file " << inputFile << "  does not exist.\n";
		exit(1);
	}
	else{
		return;
	}

}
/* toLower: Lower cases all characters in array p
*  Parameters: 
*	   p: Array used to store the paragraph
*  Precondition: p has been filled 
*  Postcondition: All characters have been lowercased
*  Returns: Nothing
*/
void toLower (char p[]){
	int i;
	for (i=0; p[i] != '\0'; i++){
		p[i]  = tolower(p[i]);
	}
}
/* readSentences: Determines the number of sentences by counting punctuation
*  Parameters: 
*	   p: Array used to store the paragraph
*  Precondition: p has a valid paragraph in it
*  Postcondition: The number of sentences has been determined and sent to main
*  Returns: The number of sentences in the paragraph
*/
int readSentences( char p[] ){
        int i;
        int count = 0;
        for(i=0; p[i] != '\0'; i++){
                if(p[i] == '.' || p[i] == '?' || p[i] == '!'){
                        count++;
                }
        }
        return (count);
}

/* tokenizeParagraph: takes an array of sentences and splits them
up by white space.
Parameters:
	p: the array holding the paragraph
	tp: the "tokenized" paragraph. A 2D array of words with punctuation.
Pre-condition: p has a valid paragraph in it and tp has been allocated space
Post-condition: tp has been filled with all words/punctuation and p has been altered to hold only its last token
Returns: the number of words in paragraph
*/
int tokenizeParagraph( char p[], char tp[][MAX_WORD_CHARS] ){
   int i = 0;
   char* cPtr;
   cPtr = strtok( p, " \n\t");
   while( cPtr != NULL )
   {
      strcpy( tp[i], cPtr );
      i++;
      cPtr= strtok( NULL, " \n\t");
   }
   return( i );
}

/* removePunc: removes punctuation from tp
*  Parameters:
*	tp: the "tokenized" paragraph. A 2D array of words with punctuation.
*	whitespace: an interger with the number of words in the paragraph.
*  Precondition: tp has been filled with all words/punctuation and white space
*		 has been given a value. 
*  Postcondition: All punctuation has been removed from tp.
*  Returns: Nothing.
*/
void removePunc(char tp[][MAX_WORD_CHARS], int whitespace){
	// First loop looking through tp first dimension
	for(int i = 0; i < whitespace; i++){
		// Second loop looking through characters of tp's other dimension
		for(int j = 0; j < MAX_WORD_CHARS; j++){
			// Third loop looking for punctuation
			for(int k = 0; k < NUM_OF_PUNC; k++){
				if(tp[i][j] == PUNCTUATION[k]){
					tp[i][j] = '\0';
				}
			}
		}
	}
}



/* readToBe: reads through tp looking for "To Be" verbs
*  Parameters: 
*	tp: the "tokenized" paragraph. A 2D array of words without punctuation.
*	whitespace: an interger with the number of words in the paragraph.
*  Precondition: tp has been filled with punctuation removed and whitespace has been
*		 given a value.
*  Postcondition: All verbs in tp have been counted.
*  Returns: Number of "To Be" Verbs in tp.
*/
int readToBe(char tp[][MAX_WORD_CHARS], int whitespace){
	int k =0;
	// First loop looking through tp
	for(int i = 0;i < whitespace;i++){
		for(int j=0;j < NUM_TO_BE_VERBS; j++){
			if(strcmp(TO_BE_VERBS[j],tp[i]) == 0){
				k++;
				break;
			}
		}
		if(strcmp(tp[i],TO) == 0){
			if(strcmp(tp[i+1], BE) == 0){
				k++;
			}
		}
	}
	return (k);
}




