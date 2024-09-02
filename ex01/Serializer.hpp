#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <stdint.h>
# include <iostream>
# include <cstdlib>

# ifndef DEBUG
#  define DEBUG 0
# endif

struct	Data
{
	int			test0;
	std::string	test1;
	char		test2;
};

class	Serializer
{
private : 

    Serializer(void);
	Serializer(Serializer const &src);
	~Serializer(void);

public :

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
	Serializer	&operator=(Serializer const &src);
};

#endif