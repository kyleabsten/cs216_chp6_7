/*
// Programmer: Kyle Absten
// Date: 03/06/2020
// Description:
	This is the first program for chapters 6 and 7 of CS216.
	This program is designed to calculate total charges for hospital patients.
	It will determine whether the patient was an inpatient or an outpatient.
	It will then ask for the relevant information for that patient and store it in the appropriate variables.
	Finally it will use one of two overloaded functions to calculate and return the total charges.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Declare needed variables

double validateValue(double);  /* Function prototype that checks the value is over 0 and returns the value.
							   If less than zero, prompts user to re-enter the value.*/
bool validateResponse(char);	/* Function prototype that checks the Y/N response is either Y or N.
								Returns true for Y and false for N*/
double calculateCharges(int, double, double, double);	/* Function prototype that caclulates the charges for in-patients.
														Arguments are int, double, double, double.  Returns a double*/
double calculateCharges(double, double);	/* Function prototype that caclulates the charges for out-patients.
											Arguments are two doubles.  Returns a double*/

int daysInHospital;	// Int; Number of days stayed in hospital.

double dayRate,	// Double; price per day of hospital stay
	hospitalCharges,	// Double; Total hospital charges
	medCharges;	// Double; Total charges for medication


int main() {
	char inpatientResponse;  // Character; Patient response for Y/N question
	bool isInpatient = false;	//Bool; was the patient and in-patient
	double totalCharges;	// Double; Total charges for all values depending on in or outpatient status

	cout << "Was the patient admitted as an in-patient? (Y/N) "; // Establish if the patient was an in-patitent or out-patient
	cin >> inpatientResponse;
	isInpatient = validateResponse(inpatientResponse);  // Set isInpatient to true or false, depending on response.
	 
	cout << "What were total hospital charges? \n";  //Get user input for hospital charges
	cin >> hospitalCharges;
	hospitalCharges = validateValue(hospitalCharges);  //Make sure response is > 0.  Assign to hospitalCharges
	cout << "What were the charges for medications? \n";	//Get user input for medication charges
	cin >> medCharges;
	medCharges = validateValue(medCharges);	//Make sure response is > 0.  Assign to medCharges
	if (isInpatient) {	//Check isInpatient;  If true, ask the two extra questions
		cout << "How many days was the patient in the hospital? \n";	//Get user input for days stayed in hospital
		cin >> daysInHospital;
		daysInHospital = validateValue(daysInHospital);	//Make sure response is > 0.  Assign to daysInHospital
		cout << "What was the day rate? \n";	//Get user input for price per day in hospital
		cin >> dayRate;
		dayRate = validateValue(dayRate);	//Make sure response is > 0.  Assign to dayRate
		
		cout << fixed << setprecision(2);	//Set the diplay of doubles
		cout << "The total charges are $" << 
			calculateCharges(daysInHospital, dayRate, hospitalCharges, medCharges);	/*Calculate the charges and return the value
																					using the appropriate overloaded 
																					calculateCharges function that accounts
																					for the hospital stay of an in-patient*/
	}
	else {	//isInpatient was false;  We have all the values we need
		cout << fixed << setprecision(2);
		cout << "The total charges are $" << calculateCharges(hospitalCharges, medCharges);	/*Calculate the charges and return 
																							the value using the appropriate
																							overloaded  calculateCharges function
																							that doesn't have the days and dayrate
																							arguments as this is an out-patient*/
	}
	return 0;
}

double validateValue(double value) { /* Function; checks the value is over 0 and returns the value.
							   If less than zero, prompts user to re-enter the value.*/
	while (value < 0) {
		cout << "That value is invalid. It must be greater than 0. Please enter a valid number: ";
		cin >> value;
	}
	return value;
}

bool validateResponse(char response) {	/* Function; checks the Y/N response is either Y or N.  If not, asks user to re-input.
								Returns true for Y and false for N*/
	while ((tolower(response) != 'y') && (tolower(response) != 'n')) {
		cout << "Sorry, that is not a valid respone.  Please try again: (Y/N) ";
		cin >> response;
	}

	if (response == 'y')
		return true;
	else
		return false;
}

double calculateCharges(int days, double rate, double hosCharges, double medCharges) {	/* Function; caclulates the charges for in-patients.
																						   Arguments are int, double, double, double.  Returns a double*/
	double daysCharge = days * rate;
	return daysCharge + hosCharges + medCharges;
}

double calculateCharges(double hosCharges, double medCharges) {	/* Function; caclulates the charges for out-patients.
																   Arguments are two doubles.  Returns a double*/

	return hosCharges + medCharges;
}