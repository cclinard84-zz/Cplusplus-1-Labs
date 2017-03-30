/* File: lab7.cpp
*  Author: Matt Clinard
*  Description: This program manipulates data about counties in the state of Tennessee.
*  Last Date Changed: 11/10/2015
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

const int MAX_COUNTIES = 16; // Max number of characters in county names

struct countyInfo
{
	string counties;
	double povertyRates;
	double perCapitaSalary;
};

void introduction( ); // Function for Introduction
// Opens file given from user input
void openFile( ifstream&,string&); // Opens Files
// Checks files to determine if they exist or not empty
void checkFileFail( ifstream&, string);
// Reads files and puts data into proper arrays
int readFile( countyInfo data[], ifstream&);
// Lower cases each letter in the county names
void toLower(countyInfo data[]);
// Sorts arrays from bottom starting with minimum values
void sortCounty(countyInfo data[], int);
// Upper cases the first letter in each county name
void upperCase(countyInfo data[]);
// Outputs data with proper spacing and signs.
void outputData(countyInfo data[], int);

int main(){
	ifstream input; // input stream
	int count; // count determined from readFile function iterations
	string inputFile; // Name given for the input stream
	countyInfo data[MAX_COUNTIES]; // used for countyInfo data structure

	introduction( ); 
	openFile( input, inputFile );
	checkFileFail( input, inputFile );
	count = readFile(data, input);
	input.close( );
	toLower(data);
	sortCounty(data, count);
	upperCase(data);
	outputData(data,  count);
	return(0);
}


/* introduction: Welcomes the user
*  Parameters: None
*  Returns: Nothing
*/
void introduction( ){
	cout << "Welcome to the Appalachian Poverty/Income Report!\n";
}

/* openFile: Opens file given from user input
*  Parameters:
*	input: ifstream name
*	inputFile: string name determined by user input for the file
*  Precondition: None
*  Postcondition: input and inputFile have been named
*  passed by reference.
*  Returns: Nothing
*/
void openFile( ifstream &input, string &inputFile ){
	cout << "Enter the input file name: ";
	cin >> inputFile;
	input.open(inputFile.c_str( ));
}

/* checkFileFail: Check to see if the file exists and if it is empty
*  Parameters:
*	      input: ifstream name
*	      inputFile: string name for the file
*  Precondition: If file does not exist or empty the program displays
*		 an error message and exits. If file exists and is valid 
*		 returns file to main.
*/
void checkFileFail( ifstream &input, string inputFile){
	
	char c;

	if (input.fail( )){
		cout << "The file " << inputFile << " does not exist.\n";
		exit(1);
	}
        input.get(c);
        if (input.eof( )){
                cout << "The file " << inputFile << " is empty.\n";
                exit(1);
        }
       	input.putback(c);
	return;
}
/* readFile: Reads file and puts data into the structure
*  Parameters:
*	      countyInfo data: structure to hold data for county name, 
*	      poverty rate, per capita salary
*	      input: ifstream name
*  Precondition: File exists, is valid, and has opened successfully
*  Postcondition: structures for counties, povertyRates, and perCapitaSalary are filled to i 
*  Returns: count of counties and their respective data.
*/
int readFile(countyInfo data[], ifstream& input ){
	int i = 0;
	getline(input, data[i].counties);
	while(!input.eof() && i < MAX_COUNTIES){
		input >> data[i].povertyRates;
		input >> data[i].perCapitaSalary;
		input.ignore(200, '\n');
		i++;
		getline(input, data[i].counties);
	}
	return i;
}

/* toLower: Lower cases all characters 
* Parameters:
*	      countyInfo data: structure to hold data for county name,
*             poverty rate, per capita salary
* Precondition: countyInfo structure has been filled with data 
* Postcondition: all characters in each county name have been lowercased. 
* Returns: Nothing
*/
void toLower(countyInfo data[]){
	for(int i = 0; i < MAX_COUNTIES; i++){
		for(int j = 0; j < MAX_COUNTIES; j++){
			data[i].counties[j] = tolower(data[i].counties[j]);
		}
	}
}


/* sortCounty: sorts data.county in the countyInfo structure from lowest to highest with 
*	       regards to alphabetical order
*  Parameters: 
*	      countyInfo data: structure to hold data for county name,
*             poverty rate, per capita salary
*             count: number of times the readFile function looped determined by i in readFile
*  Precondition: countyInfo structure has been filled
*  Postcondition: countyInfo structure has been sorted
*  Returns: Nothing 
*/
void sortCounty (countyInfo data[], int count){
	int minIndex, i, top;
	countyInfo temp;

	for(top = 0; top < count-1; top++){
	// find min from top to bottom
		minIndex = top;
		for(i = top+1; i < count; i++){
			if (data[minIndex].counties > data[i].counties)
				minIndex = i;
		}
		temp = data[minIndex];
		data[minIndex] = data[top];
		data[top] = temp;
	}

}



/* upperCase: Capitalizes the first character in each county name
*  Parameters: 
*	      countyInfo data: structure to hold data for county name,
*             poverty rate, per capita salary
*  Precondition: countyInfo structure variable data.counties has been filled with names
*  Postcondition: The first character in each county name has been capitalized
*  Returns: Nothing
*/
void upperCase(countyInfo data[]){
	for(int i = 0; i < MAX_COUNTIES; i++){
		data[i].counties[0] = toupper(data[i].counties[0]);
		for(int j = 0; j < MAX_COUNTIES; j++){;
			if(data[i].counties[j] == ' '){
				data[i].counties[j+1] = toupper(data[i].counties[j+1]);
				break;
			}
		}
	}
}
/* outputData: prints data to screen with proper organization
*  Parameters:
*             countyInfo data: structure to hold data for county name,
*             poverty rate, per capita salary
*             count: number of times the readFile function looped determined by i in readFile
* Postcondition: Prints sorted data to screen
* Returns: Nothing
*/
void outputData(countyInfo data[],  int count){
	cout << setw(8) << "Counties" << setw(18) << "Poverty Rate" << setw(15) << "Salary"; 
	cout << endl << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < count; i++){
		cout.precision(3);
        	cout << setw(15) << left << data[i].counties << setw(7);
		cout << right << showpoint << data[i].povertyRates << "%";
		cout << setw(13) << noshowpoint << setprecision(5) << "$";
		cout << setw(5) << right << data[i].perCapitaSalary << endl;
	}
}

