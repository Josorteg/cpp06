/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:15:08 by josorteg          #+#    #+#             */
/*   Updated: 2024/07/16 11:27:14 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*2 checkear que tipo es
	-char
		-1 caracter solo.
		->32 <126 "imprimible"
		- que no sea un digito (seria integer) (48-57 en ascii incluidos
	-int
		-longitud mayor que 0.
		-checkear signo y que el resto sean digitos.
	-float (.f) **-inff,+inff,nanf
		-longitud mayor que 0
		-tenga . y tenga f (pero solo 1)
		-checkear signo y que sean digitos, (.) o (f al final)
		-comprobar que la f esta en el ulltimo caracter.
	-double (.) **-inf,+inf,nan
		-longitud mayor que 0
		-tenga 1 solo punto(.)
		-checkear signo y que sean digitos y (.)
	-Keyboard (infs,nans)
		-checkear cadena*/

bool	checkChar(const std::string val)
{
	std::string ch = value[0];
	if ((value.leng() != 1) || (ch < 32) || ch > 126 ) || ( ch >= 48 && ch <= 57)
		return(false);
	return (true);
}

bool	checkInt(const std::string val)
{
	if(val.leng() < 1)
		return(false);
	for (size_t i = (0 + (val[0] == '-') + (val[0] == '+')); val[i];
			i++)
	{
		if (!std::isdigit(val.c_str()[i]))
			return (false);
	}
	return(true);
	
}

bool	checkFloat(const std::string val)
{
	
}
void	ScalarConverter::convert (std::string value)
{
	if (value.empty())
		//error
	if(checkChar(value))
		//charToALL
	if(checkInt(value))
		//intToAll
	if(checkFloat(value))
		//floatToAll
	if(checkDouble(value))
		//doubleToAll
	if(checkLiteral(value))
		//literalToAll
	else
		//error
}
