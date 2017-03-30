/*
 File: coal1.cpp
 Author: Matt Clinard
 Description:This application estimates the amount of energy in kilo 
 Joules per kilogram, the calorific value, produced by a particular 
 batch of coal using Dulong formula
 Date changed: 9/21/15
*/

#include <iostream>
using namespace std;

int main()
{

	// Variables for elements and equations
	double oxygen;
	double carbon;
	double hydrogen;
	double sulfur;
	double calorific_value;
	double percent_sum;	

	// Constants for min and max percent values of elements
	const int carbon_min = 44;
	const int carbon_max = 79;
	const int hydrogen_min = 2;
	const int hydrogen_max = 5;
	const double sulfur_min = .5;
	const double sulfur_max = 4.5;
	const int oxygen_min = 1;
	const int oxygen_max = 30;


	// Welcome Message
	cout << "Welcome to the Coal Calorific Value Calculator!\n";

	// Get element percents through user prompt
	cout << "Please enter the percent of carbon, hydrogen, sulfur, and oxygen in this coal:\n";
	cin >> carbon >> hydrogen >> sulfur >> oxygen;

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
	if (percent_sum > 100)
	{
		cout << "Percentage of elements cannot be more than 100!\n";
	}
	
	else if (percent_sum <= 100)
	{
		if ((carbon < carbon_min) || (carbon > carbon_max))
			cout << "Carbon must be between 44 and 79 percent!\n";
		
		if ((hydrogen < hydrogen_min) || (hydrogen > hydrogen_max))
			cout << "Hydrogen must be between 2 and 5 percent!\n";
		
		if ((sulfur < sulfur_min ) || (sulfur > sulfur_max))
			cout << "Sulfur must be between 0.5 and 4.5 percent!\n";
		
		if ((oxygen < oxygen_min) || (oxygen > oxygen_max))
			cout << "Oxygen must be between 1 and 30 percent!\n";
	
	
		else if ((percent_sum<=100) && (carbon>=carbon_min) && (carbon<=carbon_max) && (hydrogen>=hydrogen_min) && (hydrogen<=hydrogen_max) && (sulfur>=sulfur_min) && (sulfur<=sulfur_max) && (oxygen>=oxygen_min) && (oxygen <= oxygen_max))
	
		cout << "Coal Calorific Value: " << calorific_value << " kJ/kg \n";
	}

	// Farewell message
	cout << "Thank you for using this program!\n";
	
	return(0);
}
