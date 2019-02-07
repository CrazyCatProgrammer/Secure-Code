#include "CustomerRewards.h"

CustomerRewards::CustomerRewards()
{
	max = 0; //starting at 0, will add more during methods
	used = 0;
	data = nullptr;
}

CustomerRewards::CustomerRewards(Customer input)
{
	max = 0;
	used = 0;
	data = nullptr;
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

CustomerRewards::free()
{
	if(data != nullptr) //NEVER delete null
	{
		delete[] data;
		data = nullptr; 
	}
}

void CustomerRewards::addMemory(int slots)
{
	max += slots;
	Customer* tmpptr = new Customer[max];
	std::copy(data, data + used, tmpptr;
	free();
	data = tmpptr;
}
void CustomerRewards::cleanup()
{
	max = used;
	Customer* tmpptr = new Customer[max];
	std::copy(data, data + used, tmpptr;
	free();
	data = tmpptr;
}

void CustomerRewards::add(Customer input)
{
	if(used >= max)
		addMemory(3) //adding 3 each time memory is needed, number can be changed
	data[used] = input;
	used++;

void CustomerRewards::removeOne(int index)
{
	if(index >= used) //if index out of bounds, exit
		return;
	data[index-1] = data[used]; //used it at the end
	used--; //flag last slot for reuse
	if (max > 3 + used) //check if too much excess memory is used
		cleanup();
	
}

void CustomerRewards::printOne(int index)
{
	if(index < used)
		data[index].printAll();
	else
		std::cout<<"Index Error.";
	
}

void CustomerRewards::printBest()
{
	Customer bestCustomer;
	bestCustomer.setPrice(0);
	
	
}

void CustomerRewards::printAll()
{
	for(int i = 0; i < used; i++)
		data[i].printAll();
}
