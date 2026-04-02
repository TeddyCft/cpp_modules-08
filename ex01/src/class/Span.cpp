#include "Span.hpp"
#include <iostream>

#define MS_IT_INT std::multiset<int>::const_iterator

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
		throw Span::spanIsTooShortException();
	this->_data.insert(nb);
}

int Span::shortestSpan()
{
	if (this->_data.size() < 2)
		return (0);

	MS_IT_INT it = this->_data.begin();
	MS_IT_INT prev = it++;
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
		MS_IT_INT it = this->_data.begin();
		while (it != this->_data.end())
		{
			if (count && !(count % 10))
				std::cout << std::endl;
			std::cout << "{" << *it << "}\t";
			it++;
			count++;
		}
	}
	std::cout << std::endl << "------------" << std::endl;
	std::cout << std::endl;
}