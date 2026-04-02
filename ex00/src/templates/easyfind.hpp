#ifndef EASYFIND_HPP
# define EASYFIND_HPP

template <typename T>
typename T::const_iterator	easyfind(const T &container, int tofind)
{
	typename T::const_iterator	it;
	for (it = container.begin(); it != container.end(); it++)
	{
		if (*it == tofind)
			return (it);
	}
	return (container.end());
}

#endif