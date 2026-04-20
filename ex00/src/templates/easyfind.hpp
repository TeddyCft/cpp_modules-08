#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(const T &container, int tofind)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), tofind);
	return (it);
}

#endif