#ifndef PERSON_H
#define PERSON_H

/*
Class to hold the personal information of each person
Code Written by David Bonney

*/

#include <string>

class Person
{
public:
	Person();
	
	//getters
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	char getMiddleInitial() { return middleInitial; }
	std::string getPrefix() { return prefix; }
	std::string getMeal() { return meal; }
	std::string getAccomidations() { return accomidations; }
	int getPhoneNumber() { return phoneNumber; }
	std::string getEmail() { return email; }
	
	//setters
	void setFirstName(std::string nameIn) { firstName = nameIn; }
	void setLastName(std::string nameIn) { lastName = nameIn; }
	void setMiddleInitial(char initialIn) { middleInitial = initialIn; }
	void setPrefix(std::string prefixIn) { prefix = prefixIn; }
	void setMeal(std::string mealIn) { meal = mealIn; }
	void setAccomidations(std::string accIn) { accomidations = accIn; }
	void setPhoneNumber(int phoneIn) { phoneNumber = phoneIn; }
	void setEmail(std::string emailIn) { email = emailIn; }
		
private:
	std::string firstName;
	std::string lastName;
	char middleInitial; //preset is on 0 for testing purposes
	std::string prefix; //mr, mrs, etc.
	std::string meal;
	std::string accomidations;
	int phoneNumber;
	std::string email;
	
};

#endif





/*

secureInput(string*, int maxChar){
	check if null
	get input (cut off at maxChar)
	put input into the string pointer
	return
}
*/
