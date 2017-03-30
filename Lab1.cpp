/*
* File: coalcalc.cpp
* Author: Matt Clinard
* Description: This application will estimate the amount of energy 
* produced in kiloJoules per kilogram, produced by a particular 
* batch of coal using the Dulong formula.
* Last date changed: September 4, 2015
*/

#include <iostream>
using namespace std;

int main()
{

 	// Variables for user inputs from double carbon to oxygen, 
 	// in percentages, as well as qval which is the quotient 
 	// of the equation in kJ/kg. 
	double carbon;
	double hydrogen;
	double sulfur;
	double oxygen;
	double percentage_sum;
	double qval;
	
	// Setting decimal to show one (1) digit to the right of the decimal
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(1);

	// Welcome Message
	cout << "Welcome to the Coal Calorific Value Calculator!\n";

	// Get percent values from user for each of the elements of carbon, 
	// hydrogen, sulfur, and oxygen.
	cout << "Please enter percentages of carbon, hydrogen, sulfur, and oxygen in this coal:\n";
	cin >> carbon, hydrogen, sulfur, oxygen;

	// This equation and if statement calculates percentage sum of elements
	// to ensure the sum of the percentages is not greater than 100%.
	percentage_sum = oxygen + hydrogen + sulfur + carbon;

	// If and else if statements to maintain pertinent percent ranges of 
	// carbon, hydrogen, sulfur, and oxygen.
	if (percentage_sum <= 100)
	{
		if (carbon < 44 || carbon > 79)
		
			cout << "Carbon must be between 44% and 79%.\n";
		
		if (hydrogen < 2 || hydrogen > 5)
		
			cout << "Hydrogen must be between 2% and 5%.\n";
		
		if (sulfur < .5 || sulfur > 4.5)
		
			cout << "Sulfur must be between .5% and 4.5%.\n";
		
		if (oxygen < 1 || oxygen > 30)
		 
			cout << "Oxygen must be between 1% and 30%.\n";
		
	}
	else if (percentage_sum > 100)
	{
		cout << "Percentages cannot add up to more than 100.\n";
	}

	// Dulong Coal Calorific equation and output	
	if (percentage_sum <= 100 && carbon >= 44 && carbon <= 79 && hydrogen >= 2 && hydrogen <= 5 && sulfur >= .5 && sulfur <= 4.5 && oxygen >= 1 && oxygen <= 30)
	{
		qval = (337 * carbon + 1442 * (hydrogen - oxygen / 8) + 93 * sulfur) / 100;
		cout << "The Coal Calorific Value is: " << qval << " kJ/kg.\n";
	}
        // Farewell 
        cout << "Thank you for using this program!\n";
	
	return(0);

}
