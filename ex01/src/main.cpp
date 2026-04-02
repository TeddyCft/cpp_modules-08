#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(NULL));
	
	unsigned int size = 500; // value can be changed to perform tests
	Span span(size);
	int nb = 0;

	try
	{
		for (size_t i = 0; i < size; i++)
		{
			nb = std::rand() % (size * 10);
			span.addNumber(nb);
		}
		span.print();
		
		std::cout << "Span longest = " << span.longestSpan() << std::endl;
		std::cout << "Span shortest = " << span.shortestSpan() << std::endl;

		std::cout << std::endl << "-- trying to add a number over the max count --" << std::endl;
		span.addNumber(42);
	}
	catch (Span::spanIsFullException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}