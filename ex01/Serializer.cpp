#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called\n";
}

Serializer::Serializer(Serializer const &src __attribute__((unused)))
{
	std::cout << "Serializer copy constructor called\n";
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called\n";
}



uintptr_t	Serializer::serialize(Data	*ptr)
{
	std::cout << "Serializer serialize member function called\n";
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	std::cout << "Serializer deserialize member function called\n";
	return reinterpret_cast<Data *>(raw);
}

// Operator //

Serializer	&Serializer::operator=(Serializer const &src __attribute__((unused)))
{
	std::cout << "Serializer copy operator called\n";
	return *this;
}