// Ch 6 Paint Job Estimator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//Create necessary functions
void getRooms(double &rooms);
void getSqFt(double &squareFeet);
void gallonsForRoom(double& gallons, double& squareFeet, double &gallonsPerSqFt);
void getPricePerGallon(double &paintPrice);
void displayEstimate(double & paintCharge, double &gallonsNeeded, double &laborCharge, double &laborHours, double &rooms);

int main()
{
	//Create and intialize necessary variables
	double rooms = 0, paintPrice = 0, paintCharge = 0, laborCharge = 0, gallonsNeeded = 0, laborHours = 0, squareFeet = 0, gallons = 0, gallonsPerSqFt = 1.0/110.0, 
	laborPerSqFt = 8.0/110.0, laborPerHour = 25;

	//Call function to prompt the user to enter the number of rooms being painted
	getRooms(rooms);

	//Use a for loop to repeat and gather needed information based on how many rooms the user enters
	for (int a = 0; a < rooms; a++)
	{
		//Call function to get the square feet of each room
		getSqFt(squareFeet);
		//Call function to calculate the number of gallons needed for each room
		gallonsForRoom(gallons, squareFeet, gallonsPerSqFt); 
		//Save the number of gallons needed as gallonsNeeded
		gallonsNeeded += gallons;
		//Call function in order to prompt user to enter the cost of paint
		getPricePerGallon(paintPrice);
		//Calculate the total cost of paint and save it as paintCharge
		paintCharge += gallons * paintPrice;
		//Calculate the total number of labor hours needed 
		double labor = squareFeet * laborPerSqFt;
		//Save total number of labor hours as laborHours
		laborHours += labor;
		//Calculate the total labor cost and save as laborCharge
		laborCharge += labor * laborPerHour;
	}

	//Display all information for painting and total charges
	displayEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours, rooms);
	
}

//Create definition of function to prompt the user to enter number of rooms 
void getRooms(double &rooms)
{
	//Use a do while loop to repeat the statements if user enters information incorrectly
	do
	{
		cout << "Please enter the number of rooms to be painted: ";
		cin >> rooms;
		cout << "\n";
		//Use an if statement to validate the number of rooms being painted that the user enters
		if (rooms < 1)
		{
			cout << "The number of rooms to be painted must be greater than or equal to 1.\n";
		}
	} while (rooms < 1);
}

//Create definition of function in order to get the square feet of wall space within each room
void getSqFt(double &squareFeet)
{
	do
	{
		cout << "Enter the square feet of wall space in the room: ";
		cin >> squareFeet;
		//Use an if statement in order to validate the square feet entered by the user
		if (squareFeet <= 0)
		{
			cout << "Square feet must be greater than 0.\n";
		}
	} while (squareFeet <= 0);
}

//Create definition of function in order to calculate the number of gallons needed for each room based off the square feet
void gallonsForRoom(double &gallons, double &squareFeet, double &gallonsPerSqFt)
{
	gallons = squareFeet * gallonsPerSqFt;
	gallons = ceil(gallons);
}

//Create definition of function in order to prompt the user to enter the cost of paint per gallon
void getPricePerGallon(double &paintPrice)
{
	//Use a do while loop to repeat statements if information is invalid
	do
	{
		cout << "Please enter the price of the paint per gallon: ";
		cin >> paintPrice;
		cout << "\n";
		//Use an if statement in order to validate the information entered by the user
		if (paintPrice < 10)
		{
			cout << "The paint price has to be greater than or equal to $10.\n";
		}
	} while (paintPrice < 10);
}

//Create function definition in order to display the information for painting and the total cost of everything
void displayEstimate(double &paintCharge, double &gallonsNeeded, double &laborCharge, double &laborHours, double &rooms)
{
	cout << "Estimate for painting " << rooms << " room(s): \n";
	cout << "Gallons of paint to purchase: " << gallonsNeeded << "\n";
	cout << "Number of hours required to paint rooms: " << setprecision(4) << laborHours << "\n";
	cout << "Cost of paint: $" << paintCharge << "\n";
	cout << "Cost of labor: $" << setprecision(5) << laborCharge << "\n";
	cout << "Total cost for the job: $" << setprecision(5) << (paintCharge + laborCharge) << "\n";
}
