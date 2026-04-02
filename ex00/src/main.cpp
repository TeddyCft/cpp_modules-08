#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
	int ret = 0;

	std::vector<int> vec;
	for (size_t i = 0; i < 50; i++)
		vec.push_back(i);
	ret = *easyfind(vec, 42);
	std::cout << "looking for 42 in vec : " << ret << std::endl;

	std::list<int> list;
	for (size_t i = 0; i < 400; i++)
		list.push_back(i);
	ret = *easyfind(list, 222);
	std::cout << "looking for 222 in list : " << ret << std::endl;

	std::deque<int> dq;
	for (size_t i = 0; i < 5000; i++)
		dq.push_back(i);
	ret = *easyfind(dq, 4242);
	std::cout << "looking for 4242 in deque : " << ret << std::endl;

	if (easyfind(vec, 50) == vec.end()) //should be true because 50 doesnt exist in vec.
		std::cout << "this is fine :)" << std::endl;
	else
		std::cout << "how ?" << std::endl;
}