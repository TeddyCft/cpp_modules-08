#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>

class Span
{
	private:

	unsigned int		_maxSize;
	std::multiset<int>		_data;

	public:

	void	addNumber(int nb);
	int 	shortestSpan();
	int		longestSpan();
	void	print();

	Span(void);
	Span(unsigned int n);
	Span(const Span &copy);
	Span &operator=(const Span &og);
	~Span(void);

	class spanIsFullException : public std::exception
	{
		public :
		
		virtual const char *what() const throw()
		{ return ("This span is full, could not add number"); }
	} 	;
}	;

#endif
