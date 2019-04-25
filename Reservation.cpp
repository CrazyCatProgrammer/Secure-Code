#include "stdafx.h"
#include "Reservation.h"


Reservation::Reservation()
{
	destination = "";
	roundTrip = false;
	nonStop = false;
	bags = 0;
	max = 0;
	used = 0;
}


Reservation::~Reservation()
{
	free();
}

void Reservation::add(Person personIn)
{
	if (used >= max)
		addMemory(4); //adding 4 (size of average family) each time memory is needed, number can be changed
	people[used] = personIn;
	used++;
}

Person Reservation::operator[](int const & num)
{
	if (num < used)
		return people[num];
	return Person();
}

void Reservation::free()
{
	if (people != NULL) //NEVER delete null
	{
		delete[] people;
		people = NULL;
	}
}

void Reservation::addMemory(int slots)
{
	max += slots;
	if (max >= 0) { //overflow protection check added by David Bonney 3/11
		Person* tmpptr = new Person[max];
		std::copy(people, people + used, tmpptr);
		free();
		people = tmpptr;
	}
	else
		std::cout << "Too many people, please create a new list.\n";

}