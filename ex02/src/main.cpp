#include "MutantStack.hpp"
#include <vector>
#include <iostream>
#include <iterator>
#include <stack>

void withVect()
{
	std::vector<int> vect;
	vect.push_back(5);
	vect.push_back(17);
	std::cout << "last element is : " << vect.back() << std::endl;
	vect.pop_back();
	std::cout << "size is : " << vect.size() << std::endl;
	vect.push_back(3);
	vect.push_back(5);
	vect.push_back(737);
	//[...]
	vect.push_back(0);
	std::vector<int>::iterator it = vect.begin();
	std::vector<int>::iterator ite = vect.end();
	++it;
	--it;
	std::cout << "printing vect : " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return ;
}

void withMStack()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "stack top is : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size is : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "printing stack : " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\n -- checking compatibility --\n" << std::endl;
	std::stack<int> s(mstack);
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}	// we print stack s while destroying it to make sure
		// it has the same content as my mutantstack
	return ;
}

int main()
{
	std::cout << "-- with mutant stack --\n" << std::endl;
	withMStack();
	std::cout << std::endl << "\n-- with vector --\n" << std::endl;
	withVect();
	return (0);
}