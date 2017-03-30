* File: lab5.cpp
*  Author: Matt Clinard
*  Description: This program manipulates data about counties in the state of Tennessee.
*  Last Date Changed: 11/10/2015
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_COUNTIES = 16; // Max number of characters in county names

void introduction( ); // Function for Introduction
void openFile( ifstream&,string&); // Opens Files
// Checks files to determine if they exist or not empty
void checkFileFail( ifstream&, string);
// Reads files and puts data into proper arrays
int readFile( string[], double[], double[], ifstream&);
// Sorts arrays from bottom starting with minimum values
void sortArrays(string[], double[], double[], int);
// Outputs data with proper spacing and signs.
void outputData(string[], double[], double[], int);

int main(){
	ifstream input; // input stream
	int count; // count determined from readFile function iterations
	string inputFile; // Name given for the input stream
	string counties[MAX_COUNTIES];
	double povertyRates[MAX_COUNTIES];
	double perCapitaSalary[MAX_COUNTIES];

	introduction( ); 
	openFile( input, inputFile );
	checkFileFail( input, inputFile );
	count = readFile(counties, povertyRates, perCapitaSalary, input);
	input.close( );
	sortArrays(counties, povertyRates, perCapitaSalary, count);
	outputData(counties, povertyRates, perCapitaSalary, count);
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
*  passed by reference from user prompt.
*  Returns: Nothing
*/
void openFile( ifstream &input, string &inputFile ){
	cout << "Enter the input file name: ";
	cin >> inputFile;
	input.open(inputFile.c_str( ));
}

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
/* readFile: Reads file and puts data into proper arrays
*  Parameters:
*	      counties: array for county names
*	      poverRates: array for poverty rates in respective counties
*	      perCapitaSalary: array for Per Capita Salary in respective county
*	      input: ifstream name
*  Precondition: File exists and is valid
*  Postcondition: counties, povertyRates, and perCapitaSalary are filled to i 
*  Returns: i
*/
int readFile(string counties[], double povertyRates[], double perCapitaSalary[], ifstream& input ){
	int i = 0;
	while( i < MAX_COUNTIES){
		input >> counties[i];
		input >> povertyRates[i];
		input >> perCapitaSalary[i];
		i++;
	}
	return i;
}

/* sortArrays: sorts arrays from lowest to highest with regards to poverty rates
*  Parameters: 
*	      counties: array for county names
*             povertyRates: array for poverty rates in respective counties
*             perCapitaSalary: array for Per Capita Salary in respective county
*             count: number of times the readFile function looped determined by i in readFile
*  Precondition: counties, povertyRates, and perCapitaSalary have been filled
*  Postcondition: arrays have been sorted
*  Returns: Nothing 
*/
void sortArrays ( string counties[], double povertyRates[], double perCapitaSalary[], int count){
	int minIndex, i, top;
	double temp;
	double temp2;
	string temp3;

	for(top = 0; top < count-1; top++){
	// find min from top to bottom
		minIndex = top;
		for(i = top+1; i < count; i++){
			if (povertyRates[minIndex] > povertyRates[i])
				minIndex = i;
		}
		temp = povertyRates[minIndex];
		povertyRates[minIndex] = povertyRates[top];
		povertyRates[top] = temp;
		
		temp2 = perCapitaSalary[minIndex];
		perCapitaSalary[minIndex] =  perCapitaSalary[top];
		perCapitaSalary[top] = temp2;

		temp3 = counties[minIndex];
		counties[minIndex] = counties[top];
		counties[top] = temp3;
	}

}

/* outputData: prints data to screen with proper organization
*  Parameters:
*             counties: array for county names
*             povertyRates: array for poverty rates in respective counties
*             perCapitaSalary: array for Per Capita Salary in respective county
*             count: number of times the readFile function looped determined by i in readFile
* Postcondition: Prints sorted data to screen
* Returns: Nothing
*/
void outputData(string counties[], double povertyRates[], double perCapitaSalary[], int count){
	cout << "Counties" << setw(15) << "Poverty Rate" << setw(15) << "Salary"; 
	cout << endl << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	for (int i = 0; i < count; i++){
        	cout << setw(12) << left << counties[i] << setw(7) << right << povertyRates[i] << "%" << setw(13) << "$" << right <<  perCapitaSalary[i] <<"\n";

	}
}

