// Ch 6 Paint Job Estimator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void getRooms(double &rooms);
void getSqFt(double &squareFeet);
void gallonsForRoom(double& gallons, double& squareFeet, double &gallonsPerSqFt);
void getPricePerGallon(double &paintPrice);
void displayEstimate(double & paintCharge, double &gallonsNeeded, double &laborCharge, double &laborHours, double &rooms);

int main()
{
	double rooms = 0, paintPrice = 0, paintCharge = 0, laborCharge = 0, gallonsNeeded = 0, laborHours = 0, squareFeet = 0, gallons = 0, gallonsPerSqFt = 1.0/110.0, 
	laborPerSqFt = 8.0/110.0, laborPerHour = 25;

	getRooms(rooms);

	for (int a = 0; a < rooms; a++)
	{
		getSqFt(squareFeet);
		gallonsForRoom(gallons, squareFeet, gallonsPerSqFt); \
		gallonsNeeded += gallons;
		getPricePerGallon(paintPrice);
		paintCharge += gallons * paintPrice;
		double labor = squareFeet * laborPerSqFt;
		laborHours += labor;
		laborCharge += labor * laborPerHour;
	}

	displayEstimate(paintCharge, gallonsNeeded, laborCharge, laborHours, rooms);
	
}

void getRooms(double &rooms)
{
	do
	{
		cout << "Please enter the number of rooms to be painted: ";
		cin >> rooms;
		cout << "\n";
		if (rooms < 1)
		{
			cout << "The number of rooms to be painted must be greater than or equal to 1.\n";
		}
	} while (rooms < 1);
}

void getSqFt(double &squareFeet)
{
	do
	{
		cout << "Enter the square feet of wall space in the room: ";
		cin >> squareFeet;
		if (squareFeet <= 0)
		{
			cout << "Square feet must be greater than 0.\n";
		}
	} while (squareFeet <= 0);
}

void gallonsForRoom(double &gallons, double &squareFeet, double &gallonsPerSqFt)
{
	gallons = squareFeet * gallonsPerSqFt;
	gallons = ceil(gallons);
}

void getPricePerGallon(double &paintPrice)
{
	do
	{
		cout << "Please enter the price of the paint per gallon: ";
		cin >> paintPrice;
		cout << "\n";
		if (paintPrice < 10)
		{
			cout << "The paint price has to be greater than or equal to $10.\n";
		}
	} while (paintPrice < 10);
}

void displayEstimate(double &paintCharge, double &gallonsNeeded, double &laborCharge, double &laborHours, double &rooms)
{
	cout << "Estimate for painting " << rooms << " room(s): \n";
	cout << "Gallons of paint to purchase: " << gallonsNeeded << "\n";
	cout << "Number of hours required to paint rooms: " << setprecision(4) << laborHours << "\n";
	cout << "Cost of paint: $" << paintCharge << "\n";
	cout << "Cost of labor: $" << setprecision(5) << laborCharge << "\n";
	cout << "Total cost for the job: $" << setprecision(5) << (paintCharge + laborCharge) << "\n";
}
