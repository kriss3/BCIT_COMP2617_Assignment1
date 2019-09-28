#pragma once
#include<iostream>

// Assignment 01 Solution: Employee.h
// Definition of Employee class.
// 
// Krzysztof Szczurowski
// September 20, 2019

class Employee
{
public:
	explicit Employee(std::string firstName, std::string lastName, int monthlySalary); // ctor initializes first name, last name and montly salary

	void setFirstName(std::string firstName); // mutator method for the fist name;

	std::string getFirstName() const; //accessor method for the first name;

	void setLastName(std::string lastName); //mutator method for the last name;

	std::string getLastName() const; //accessor method for the last name;

	void setMonthlySalary(int salary); //mutator method for the montly salary;

	int getMonthlySalary() const; //accessor method for the montly salary;
	
private:
	std::string firstName;  // fist name class member;
	std::string lastName; // last name class member;
	int monthlySalary; // montly salary class member;
	void displayWarningMsg(int property) const; //private method to display warining messages thrown in ctor. Method only available for internal workings of the class;
	void displayErrorMsg(char propertyName, std::string currentValue) const; //private method to display error methods thrown in mutator methods; Method only available for internal workings of the class;
}; //end of Employee class definisiton;

