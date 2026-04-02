#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <iterator>

class Span
{
	private:

	unsigned int		_maxSize;
	std::multiset<int>		_data;

	public:

	//template function must be declared in the hpp in order to be understood by the compiler.
	template <typename Iterator>
	void addNumber(Iterator begin, Iterator end)
	{
		unsigned int toAdd = static_cast<unsigned int>(std::distance(begin, end));
		toAdd += this->_data.size();
		if (toAdd > this->_maxSize)
			throw Span::spanIsTooShortException();
		this->_data.insert(begin, end);
	}

	void	addNumber(int nb);
	int 	shortestSpan();
	int		longestSpan();
	void	print();

	Span(void);
	Span(unsigned int n);
	Span(const Span &copy);
	Span &operator=(const Span &og);
	~Span(void);

	class spanIsTooShortException : public std::exception
	{
		public :
		
		virtual const char *what() const throw()
		{ return ("This span is too short"); }
	} 	;
}	;



#endif