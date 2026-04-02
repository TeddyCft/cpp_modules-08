#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#define SPAN_SIZE 5 // value can be changed to perform tests
#define VEC_SIZE 5 // value can be changed to perform tests

void simple_add()
{
	Span span(SPAN_SIZE);
	int nb = 0;

	for (size_t i = 0; i < SPAN_SIZE; i++)
	{
		nb = std::rand() % (SPAN_SIZE * 10);
		span.addNumber(nb);
	}
	span.print();
	
	std::cout << "Span longest = " << span.longestSpan() << std::endl;
	std::cout << "Span shortest = " << span.shortestSpan() << std::endl;

	std::cout << std::endl << "-- trying to add a number over the max count --" << std::endl;
	span.addNumber(42);
}

void range_add()
{
	Span span(SPAN_SIZE);
	std::vector<int> vec;
	int nb = 0;
	for (size_t count = 0; count < SPAN_SIZE; count += VEC_SIZE)
	{
		vec.clear();
		for (size_t i = 0; i < VEC_SIZE; i++)
		{
			nb = std::rand() % (SPAN_SIZE * 10);
			vec.push_back(nb);
		}
		span.addNumber(vec.begin(), vec.end());
	}
	span.print();
	std::cout << "Span longest = " << span.longestSpan() << std::endl;
	std::cout << "Span shortest = " << span.shortestSpan() << std::endl;
}

int main()
{
	std::srand(std::time(NULL));

	std::cout << "==== simple add ====" << std::endl;

	try
	{ simple_add(); }
	catch (Span::spanIsTooShortException &e)
	{ std::cout << e.what() << std::endl; }

	std::cout << std::endl << "==== range add ====" << std::endl;

	try
	{ range_add(); }
	catch (Span::spanIsTooShortException &e)
	{ std::cout << e.what() << std::endl; }

	return (0);
}