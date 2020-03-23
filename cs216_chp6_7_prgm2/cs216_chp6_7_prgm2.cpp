/*
// Programmer: Kyle Absten
// Date: 03/07/2020
// Description:
	This is the second program for chapters 6 and 7 of CS216.
	This program is to demonstrate the creation and use of a Class.
	The class will be called Inventory and will model an item in a stores inventory.
	
	The program will show the use of the class object.

	One note for the professor.  This question was really poorly written in the book.  It talks about a setTotalCost function
	in the description of one of the constructors, but doesn't mention it again.  It also doesn't mention a totalCost member 
	variable. That function is a bad idea, as the data would be stale if the quantity or cost variables were changed.
	I accounted for this in the getTotalCost function, which computes and returns the value with the current cost and
	quantity values.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int validateInput(int);  /* Overloaded function prototype; Takes an int, checks that it isn't negative, and returns the int.
						 If negative input, prompts user to re-input*/
double validateInput(double);  /* Overloaded function prototype; Takes a double, checks that it isn't negative, and returns
							   the double.  If negative input, prompts user to re-input*/

class Inventory {  //Class;  Models an item in inventory.

private:
	int itemNumber,  //Int; the item number used to catalog the item
		quantity;	//Int; Quantity of item in stock

	double cost,	//Double; Cost of one unit
		totalCost;	/* Double; total cost of quantity in stock.  This was mentioned in the second constructor.  Not a good 
					practice as the data will become stale if the quantity or cost member variables are changed.*/

public:
	Inventory();	//Overloaded constructor prototype; Accepts no arguments. Defined outside class.
	Inventory(int, int, double);	//Overloaded constructor prototype; Accept int, int, double arguments.  Defined outside class.

	void setItemNumber(int number) {  //Inline mutator member function;Accepts int and sets itemNumber member variable equal to it.
		itemNumber = number;
	}

	void setQuantity(int number) {	//Inline mutator member function;Accepts int and sets quantity member variable equal to it.
		quantity = number;
	}

	void setCost(double number) {	//Inline mutator member function;Accepts double and sets cost member variable equal to it.
		cost = number;
	}

	void setTotalCost() {	//Inline mutator member function;Accepts double and sets totalCost member variable equal to it.
		totalCost = quantity * cost;
	}

	int getItemNumber() {	//Inline accessor member function;Accepts no arguments, returns int equal to value of itemNumber member variable.
		return itemNumber;
	}

	int getQuantity() {	//Inline accessor member function;Accepts no arguments, returns int equal to value of quantity member variable.
		return quantity;
	}

	double getCost() {	//Inline accessor member function;Accepts no arguments, returns double equal to value of cost member variable.
		return cost;
	}

	double getTotalCost() {	/*Inline accessor member function;Accepts no arguments,
							returns double equal to value of cost member variable * quantity member variable.*/
		return quantity * cost;
	}

};



int main() {
	int partNumber, //Int; holds the partnumber entered
		quantity;	//Int; holds the quantity number entered
	double cost;	//Double; holds the cost number entered.

	cout << "Enter the item's part number: ";
	cin >> partNumber;
	partNumber = validateInput(partNumber);  //Checks that part number is not negative.
	cout << "Enter the quantity in stock: ";
	cin >> quantity;
	quantity = validateInput(quantity);  //Checks that part number is not negative.
	cout << "Enter the cost of 1 unit: ";
	cin >> cost;
	cost = validateInput(cost);  //Checks that part number is not negative.  

	Inventory item(partNumber, quantity, cost);  //Create Inventory object called item using user input as arguments
	
	cout << fixed << setprecision(2);
	cout << "\nItem #: " << item.getItemNumber();  //Calls the getItemNumber member function
	cout << "\nQuantity in stock: " << item.getQuantity(); //Calls the getQuantity member function
	cout << "\nCost per unit: " << item.getCost(); //Calls the getCost member function
	cout << "\nTotal value of item in stock: $" << item.getTotalCost() << endl; //Calls the getTotalCost member function

	return 0;
}



int validateInput(int input) {  /*Overloaded function; Accepts int, checks that it is not negative, returns value
								as int. If value is negative, prompts user to re-input the value*/
	while (input < 0) {
		cout << "Sorry, that is not a valid input.  Please enter a non-negative number: ";
		cin >> input;
	}
	return input;
}

double validateInput(double input) {	/*Overloaded function; Accepts a double, checks that it is not negative, returns 
										value as double. If value is negative, prompts user to re-input the value*/
	while (input < 0) {
		cout << "Sorry, that is not a valid input.  Please enter a non-negative number: ";
		cin >> input;
	}
	return input;
}

Inventory::Inventory() { //Overloaded constructor of Inventory class; Takes no arguments.  Sets all private member variables equal to 0
	setItemNumber(0);
	setQuantity(0);
	setCost(0);
}

Inventory::Inventory(int itemNumber, int quantity, double cost) {  /* Overloaded constructor of Inventory class
																   Accepts int itemNumber, int quantity and double cost.
																   Sets private member variable using the set member functions*/
	setItemNumber(itemNumber);
	setQuantity(quantity);
	setCost(cost);
	setTotalCost();
}