#include "CustomerRewards.h"

CustomerRewards::CustomerRewards()
{
	max = 0; //starting at 0, will add more during methods
	used = 0;
	data = NULL;
}

CustomerRewards::CustomerRewards(Customer input)
{
	max = 0;
	used = 0;
	data = NULL;
	add(input);
}

CustomerRewards::~CustomerRewards()
{
	free();
}

CustomerRewards::CustomerRewards(const CustomerRewards & source)
{
	used = source.used;
	max = source.max;
	data = nullptr;
	data = new Customer[max];
	std::copy(source.data, source.data + source.used, data);
}

CustomerRewards & CustomerRewards::operator=(const CustomerRewards & source)
{
	if (this == &source)
		return *this;
	free();
	used = source.used;
	max = source.max;
	data = new Customer[max];
	std::copy(source.data, source.data + source.used, data);
	return *this;
}

void CustomerRewards::free()
{
	if (data != NULL) //NEVER delete null
	{
		delete[] data;
		data = NULL;
	}
}

void CustomerRewards::addMemory(int slots)
{
	max += slots;
	Customer* tmpptr = new Customer[max];
	std::copy(data, data + used, tmpptr);
	free();
	data = tmpptr;
}
void CustomerRewards::cleanup()
{
	max = used;
	Customer* tmpptr = new Customer[max];
	std::copy(data, data + used, tmpptr);
	free();
	data = tmpptr;
}

void CustomerRewards::add(Customer input)
{
	if (used >= max)
		addMemory(3); //adding 3 each time memory is needed, number can be changed
	data[used] = input;
	used++;
}
void CustomerRewards::removeOne(int index)
{
	if (index >= used) //if index out of bounds, exit
		return;
	data[index] = data[used]; //used it at the end
	used--; //flag last slot for reuse
	if (max > 3 + used) //check if too much excess memory is used
		cleanup();
}

void CustomerRewards::printOne(int index)
{
	if (index < used)
		data[index].printAll();
	else
		std::cout << "Index Error.";
}

void CustomerRewards::printBest()
{
	Customer bestCustomer;
	bestCustomer.setName("No Customers"); //if there are no customers with any price >= 0, it will show there is no customers
	bestCustomer.setPrice(0.0);
	for (int i = 0; i < used; i++)
	{
		if (data[i].getPrice() >= bestCustomer.getPrice()) //Uses >= because most recent entry should have precedence over older entries for "best"
		{												   //if current index is better than previous best...
			bestCustomer.setName(data[i].getName());       //change info to match
			bestCustomer.setPrice(data[i].getPrice());
		}
	}
	bestCustomer.printAll();
}

void CustomerRewards::printAll()
{
	for (int i = 0; i < used; i++) {
		std::cout << "Customer " << i+1 << ":" << std::endl;
		data[i].printAll();
	}
}

Customer CustomerRewards::operator[](int const & num) 
{
	if (num < used)
		return data[num];
	return Customer();
}

