/* File: coalfunc.cpp
*  Author: Matt Clinard
*  Description: This application estimates the amount of energy in kilo Joules 
*  per kilogram, the calorific value, produced by a particular batch of coal 
*  using Dulong formula 
*  Last Date Changed: 10/9/2015
*/

#include <iostream>
#include <cmath>
using namespace std;
	
	const double CARBON_MIN = 44.0;
	const double CARBON_MAX = 79.0;
	const double HYDRO_MIN = 2.0;
	const double HYDRO_MAX = 5.0;
	const double SULFUR_MIN = .5;
	const double SULFUR_MAX = 4.5;
	const double OXYGEN_MIN = 1.0;
	const double OXYGEN_MAX = 30.0;

	void introduction( );
	void getPercents( double& c, double& h, double& s, double& o);
	double percentSum( double c, double h, double s, double o);
	bool badRanges( double c, double h, double s, double o, bool& cBad, bool& hBad, bool& sBad, bool& oBad);
    	double calcCalorific( double c, double h, double s, double o);

int main() {
    	 
   double calorific; // in kJ/kg
   double c, h, s, o; // percents. 100=100%
   bool cBad, hBad, sBad, oBad; // true if element percent out of range

   cout.setf( ios::fixed | ios::showpoint );
   cout.precision( 1 );

   introduction(); // Welcome message

   // get element percentages from user
   getPercents( c, h, s, o);
   while ( c != 0 ) {
      // if element percentages over 100
      if ( percentSum( c, h, s, o) > 100 ) {
	
         cout << "Percentages cannot add up to more than 100.\n";
      }
      
	// if any element percentage value is out of valid range
	else if (badRanges( c, h, s, o, cBad, hBad, sBad, oBad ) ) {
		if ( cBad ) 
            		cout << "Carbon must be between 44% and 79%.\n";
         	
         	if ( hBad ) 
            		cout << "Hydrogen must be between 2% and 5%.\n";
         	
         	if ( sBad ) 
            		cout << "Sulfur must be between 0.5% and 4.5%.\n";
         	
         	if ( oBad ) 
            		cout << "Oxygen must be between 1% and 30%.\n";
         	
      	}
      
	// if element percentages all in range/valid
        else {
        	calorific = calcCalorific ( c, h, s, o);

		cout << "Coal Calorific Value: " << calorific << " kJ/kg\n";
      	}
      
	// get element percentages from user for next batch of coal
        getPercents( c, h, s, o);
   	} // end while carbon percent != 0

   	cout << "Thank you for using this program!\n";

   return 0;
}

/* introduction: Welcomes the user
*   Parameters: None
*   Precondition: Program has started
*   Postcondition: Welcome message
*   Returns: Nothing
*/
	void introduction ( ) {
		cout << "Welcome to the Coal Calorific Calculator!\n";
	}

/* getPercents: Prompts user for percent values of elements present in the coal
*   Parameters: c,h,s,o
*   Precondition: c has a value that does not equal zero.
*   Postcondition: c, h, s, and o have values passed by reference from user prompt.
*   Returns: nothing
*/
	
	void getPercents( double& c, double& h, double& s, double& o) {
		cout << "Please enter the percent value  of carbon  in this coal:\n";
		cin >> c;
		if (c > 0){ 
			cout << "Please enter the percent value of hydrogen, sulfur, and oxygen in this coal: \n";
			cin >> h >> s >> o;
		}
		else{
			return;
		}
	}

/*  percentSum: Uses addition to add the values of percents to determine if they are in range.
*   Parameters: c != 0
*   Precondition: c, h, s, o
*   Postcondition: c, h, s , and o are added together
*   Return: sum of c+h+s+o
*/

	double percentSum ( double c, double h, double s, double o){

		return c+h+s+o;
	}

/*  badRanges: Determines if values entered by user are within desired ranges for the elements assigned.
*   Parameters: cBad, hBad, sBad, oBad
*   Precondition: c != 0
*   Postcondition:(c,s,h,o)Bad parameters are changed if element is out of range.
*   Return: true if out of  range, false if within range.
*/
				
	bool badRanges ( double c, double h, double s, double o, bool& cBad, bool& hBad, bool& sBad, bool& oBad){
		if ((c < CARBON_MIN) || (c > CARBON_MAX))
			cBad = true;
		else
			cBad = false;
		
		if ((h < HYDRO_MIN) || (h > HYDRO_MAX))
			hBad = true;
		else
			hBad = false;
		
		if ((s < SULFUR_MIN) || (s > SULFUR_MAX))
			sBad = true;
		else
			sBad = false;
		
		if ((o < OXYGEN_MIN) || (o > OXYGEN_MAX))
			oBad = true;
		else
			oBad = false;
		
		if (cBad || hBad || sBad || oBad)
			return true;
		
		else
			return false;
		
	}

/*  calcCalorific: Determines calorific value using Dulong formula in kg/kJ.
*   Parameters: c, h, s, o
*   Precondition: Percent of elements are within range
*   Postcondition: Calorific value is computed
*   Return: calorific value
*/

	double calcCalorific ( double c, double h, double s, double o ){

		return ((337 * c) + (1442 * (h - o / 8)) + (93 * s ))/(100);
	}

		


