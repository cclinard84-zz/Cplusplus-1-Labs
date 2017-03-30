/*
 File: coaloop.cpp
 Author: Matt Clinard
 Description:This application estimates the amount of energy in kilo 
 Joules per kilogram, the calorific value, produced by a particular 
 batch of coal using Dulong formula
 Date changed: 10/4/15
*/

#include <iostream>
using namespace std;

	// Constants for min and max percent values of elements
        const int CARBON_MIN = 44;
        const int CARBON_MAX = 79;
        const int HYDROGEN_MIN = 2;
        const int HYDROGEN_MAX = 5;
        const double SULFUR_MIN = .5;
        const double SULFUR_MAX = 4.5;
        const int OXYGEN_MIN = 1;
        const int OXYGEN_MAX = 30;

int main()
{

	// Variables for elements and equations
	double oxygen; // percent of oxygen
	double carbon; // percent of carbon
	double hydrogen; // percent of hydrogen
	double sulfur; // percent of sulfur
	double calorific_value; // calculated calorific value of coal
	double percent_sum; // sum of the percentages from user prompt

	// Welcome Message
	cout << "Welcome to the Coal Calorific Value Calculator!\n";
	
	do {
		// Get element percents through user prompt
		cout << "Please enter the percent of carbon in this coal(enter 0 to end)\n";
		cin >> carbon;
	
		if ( carbon > 0 ) {
	
			cout << "Please enter the percent of hydrogen, sulfur, and oxygen in this coal:\n";
			cin >> hydrogen >> sulfur >> oxygen;

			// Setting decimal to show tenths position
			cout.setf(ios::fixed | ios::showpoint);
			cout.precision(1);
	
			// Equation to determine if element percent values 
			// are above 100%
			percent_sum = (carbon+oxygen+hydrogen+sulfur);
	
			// Dulong equation to determine Calorific Value
			calorific_value = ((337 * carbon) + (1442 * (hydrogen - oxygen/8)) + (93 * sulfur))/(100);

			// If else statements to ensure element boundries
			// are maintained with outputs to ensure correct
			// program behavior
			if (percent_sum > 100) {
				cout << "Percentage of elements cannot be more than 100!\n";
			}
	
			else if (percent_sum <= 100)
			{
				if ((carbon < CARBON_MIN) || (carbon > CARBON_MAX))
					cout << "Carbon must be between 44 and 79 percent!\n";
		
				if ((hydrogen < HYDROGEN_MIN) || (hydrogen > HYDROGEN_MAX))
					cout << "Hydrogen must be between 2 and 5 percent!\n";
		
				if ((sulfur < SULFUR_MIN ) || (sulfur > SULFUR_MAX))
					cout << "Sulfur must be between 0.5 and 4.5 percent!\n";
		
				if ((oxygen < OXYGEN_MIN) || (oxygen > OXYGEN_MAX))
					cout << "Oxygen must be between 1 and 30 percent!\n";
	
	
				else if ((percent_sum<=100) && (carbon>=CARBON_MIN) && (carbon<=CARBON_MAX) && (hydrogen>=HYDROGEN_MIN) && (hydrogen<=HYDROGEN_MAX) && (sulfur>=SULFUR_MIN) && (sulfur<=SULFUR_MAX) && (oxygen>=OXYGEN_MIN) && (oxygen <= OXYGEN_MAX))
	
					cout << "Coal Calorific Value: " << calorific_value << " kJ/kg \n";
				}	
			}
	        
		} while ( carbon > 0 );
		
			// Farewell message
			cout << "Thank you for using this program!\n";
	
	return(0);
}
