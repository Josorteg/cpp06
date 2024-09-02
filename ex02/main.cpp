#include "Base.hpp"
#include <iostream>

int	main( void )
{
	Base	*base;

	base = generate();
	identify( base );
	identify( *base );
	return ( 0 );
}