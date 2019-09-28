// Assignment 01 Solution: Employee.cpp
// 
// Krzysztof Szczurowski
// September 20, 2019

#include <iostream>
#include "Employee.h"  // include definition of class Employee
#include<string>

using namespace std;

// named constants use for better clarity when used in the program logic;
const int MIN_CHAR_NUMBER = 2;
const int DEFAULT_SALARY = 0;
const int FIRST_NAME_WARNING = 0;
const int LAST_NAME_WARNING = 1;
const int SALARY_WARNING = 2;

// Employee constructor initializes data members: first name, last name and monthly salary;
Employee::Employee(string firstName, string lastName, int monthlySalary) :
	firstName(firstName), lastName(lastName), monthlySalary(monthlySalary)
{
	if (firstName.size() < MIN_CHAR_NUMBER)
	{
		displayWarningMsg(FIRST_NAME_WARNING); //warning thrown if ctor value of first name has less than two characters length
	}
	else
	{
		setFirstName(firstName);  // setting first name via set method call;
	}

	if (lastName.size() < MIN_CHAR_NUMBER)
	{
		displayWarningMsg(LAST_NAME_WARNING); //warning thrown if ctor value of last name has less than two characters length
	}
	else
	{
		setLastName(lastName); // setting last name via set method call;
	}
	
	if (monthlySalary < DEFAULT_SALARY)
	{
		displayWarningMsg(SALARY_WARNING);
		setMonthlySalary(DEFAULT_SALARY);  //setting default salary if ctor montly salary less than 0;
	}
	else 
	{
		setMonthlySalary(monthlySalary);  // setting montly salary via set method call;
	}
} // end Employee constructor

// return first name 
string Employee::getFirstName() const
{
	return firstName;
}

// set mothod to set class member first name;
void Employee::setFirstName(string name) 
{
	if (name.size() < MIN_CHAR_NUMBER)
	{
		displayErrorMsg('F', name); // calling display error message by passing property fist letter (F-irst Name) and the value client is trying to set;
	}
	else
	{
		firstName = name;  // setting fist name value;
	}
}

// returns last name of the class member;
string Employee::getLastName() const
{
	return lastName;  
}

void Employee::setLastName(string name)
{
	if (name.size() < MIN_CHAR_NUMBER)
	{
		displayErrorMsg('L', name);  // calling display error message by passing property fist letter (L-ast Name) and the value client is trying to set;
	}
	else 
	{
		lastName = name;  // setting last name value;
	}
}

// returns montly salary;
int Employee::getMonthlySalary() const
{
	return monthlySalary;
} // end function getMonthlySalary()

void Employee::setMonthlySalary(int salary) 
{
	if (salary < DEFAULT_SALARY)
	{
		displayErrorMsg('S', to_string(salary));  // calling display error message by passing property fist letter (S-alary) and the value client is trying to set;
	}
	else 
	{
		monthlySalary = salary;  // setting employee salary;
	}
}

//Warning messages are executed from ctor;
//param:
//propertyName of type char; holds property character name; 
void Employee::displayWarningMsg(int property) const 
{
	switch (property)
	{
	case FIRST_NAME_WARNING:
		cerr << "\nWarning - invalid length string entered for first name in ctor: " << firstName << "\n" <<
			"The string that was entered will be used for now.\n";
		break;
	case LAST_NAME_WARNING:
		cerr << "\nWarning - invalid length string entered for last name in ctor: " << lastName << "\n" <<
			"The string that was entered will be used for now.\n";
		break;
	case SALARY_WARNING:
		cerr << "\nInvalid salary amount specified in ctor: $" << monthlySalary << "\n" <<
			"Salary set to $" << DEFAULT_SALARY << " instead." << "\n";
		break;
	default:
		cerr << "\nERROR - Unspecified error. Please, constact support.\n";
		break;
	}
}

//Error messages are thrown from accessors and muttators;
//params: 
//propertyName of type char; holds property character name; 
//currentValue of type string, holds current value passed to the muttator;
void Employee::displayErrorMsg(char propertyName, string currentValue) const
{
	switch (tolower(propertyName))
	{
	case 'f' :
		cerr << "\nERROR - invalid length string entered for first name in setFirstName(): " << currentValue <<
			"\nThe first name was left unchanged: " << getFirstName() << "\n";
		break;
	case 'l' :
		cerr << "\nERROR - invalid length string entered for last name in setLastName(): " << currentValue
			<< "\nThe last name was left unchanged: " << getLastName() << "\n";
		break;
	case 's' :
		cerr << "\nERROR - Invalid salary amount specified: $" << currentValue <<
			"\nSalary was left unchanged at: $" << getMonthlySalary() << "\n";
		break;
	default:
		cerr << "\nERROR - Unspecified error. Please, constact support.\n";
		break;
	}
}