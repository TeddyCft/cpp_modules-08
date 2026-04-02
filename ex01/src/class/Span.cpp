#include "Span.hpp"
#include <iostream>

//= Operator overloader
Span	&Span::operator=(const Span &og)
{
	if (this == &og)
		return (*this);
	this->_data.clear();
	this->_maxSize = og._maxSize;
	this->_data = og._data;
	return (*this);
}

//Copy constructor
Span::Span(const Span &copy)
{ *this = copy ; }

Span::Span(unsigned int n) : _maxSize(n)
{}

//Default constructor
Span::Span(void) : _maxSize(0)
{}

//Destructor
Span::~Span(void)
{}

void	Span::addNumber(int nb)
{
	if (this->_data.size() == this->_maxSize)
		throw Span::spanIsFullException();
	this->_data.insert(nb);
}

int Span::shortestSpan()
{
	if (this->_data.size() < 2)
		return (0);
	std::multiset<int>::const_iterator it = this->_data.begin();
	std::multiset<int>::const_iterator prev = it++;
	int shortest = *it - *prev;
	int diff = shortest;
	while (true)
	{
		prev = it++;
		if (it == this->_data.end())
			return (shortest);
		diff = *it - *prev;
		if (diff < shortest)
			shortest = diff;
	}
}

int	Span::longestSpan()
{
	if (this->_data.size() < 2)
		return (0);
	return (*this->_data.rbegin() - *this->_data.begin());
}

void	Span::print()
{
	std::cout << "------------" << std::endl;
	if (this->_maxSize >= 50)
		std::cout << "span is too big to be displayed";
	else
	{

		int count = 0;
		std::multiset<int>::const_iterator it = this->_data.begin();
		while (it != this->_data.end())
		{
			std::cout << "{" << *it << "} ";
			it++;
			count++;
			if (!(count % 10))
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << "------------" << std::endl;
	std::cout << std::endl;
}