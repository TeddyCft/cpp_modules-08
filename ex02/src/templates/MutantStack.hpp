#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private :

	public :

	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	//// methods
	iterator begin() 
	{ return (this->c.begin()); }
	
	iterator end()
	{ return (this->c.end()); }

	const_iterator begin() const
	{ return (this->c.begin()); }
	
	const_iterator end() const
	{ return (this->c.end()); }

	//// cannonical form 

	// default constructor
	MutantStack(void)
	{}
	// copy constructor
	MutantStack(const MutantStack &copy)
	{ *this = copy; }
	// default destructor
	~MutantStack(void)
	{}
	// assignation operator
	MutantStack &operator=(const MutantStack &og)
	{
		if (this == &og)
			return (*this);
		this->c = og.c;
		return (*this);
	}
} ;

#endif