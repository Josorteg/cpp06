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


#include"Converter.hpp"
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

bool	ScalarConverter::checkChar(std::string val)
{
	char ch = val[0];
	if ((val.length() != 1) || ((ch < 32) || (ch > 126 )) || ( ch >= 48 && ch <= 57))
		return(false);
	return (true);
}

bool	ScalarConverter::checkInt(std::string val)
{
	if(val.length() < 1)
		return(false);
	for (size_t i = (0 + (val[0] == '-') + (val[0] == '+')); val[i];
			i++)
	{
		if (!std::isdigit(val.c_str()[i]))
			return (false);
	}
	return(true);
	
}

bool	ScalarConverter::checkFloat(std::string val)
{	
	int dot = 0;
	for (size_t i = (0 + (val[0] == '-') + (val[0] == '+'));
			val[i] && (val[i] != 'f'); i++)
	{
		if (!std::isdigit(val.c_str()[i]) and val[i] != '.')
			return (false);
		else if (val[i] == '.')
		{
			if (dot > 0)
				return (false);
			dot++;
		}
	}
	if (val[val.length() - 1] != 'f')
			return (false);
	return (true);
}

bool ScalarConverter::checkDouble(const std::string val)
{
	int dot = 0;
	for (size_t i = (0 + (val[0] == '-') + (val[0] == '+'));
			val[i]; i++)
	{
		if (!std::isdigit(val.c_str()[i]) and val[i] != '.')
			return (false);
		else if (val[i] == '.')
		{
			if (dot > 0)
				return (false);
			dot++;
		}
	}
	return (true);
}

bool ScalarConverter::checkLiteral(const std::string val)
{
	std::string words[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	for (size_t i = 0; i < 6; i++)
	{
		if (words[i] == val)
			return (true);
	}	   
	return (false);
}
void	ScalarConverter::convert (std::string value)
{
	bool		( *checkType[ 5 ] )( const std::string ) = { \
										ScalarConverter::checkChar, \
										ScalarConverter::checkInt, \
										ScalarConverter::checkFloat, \
										ScalarConverter::checkDouble, \
										ScalarConverter::checkLiteral };
	std::string (type[5]) = {"Char","Int","Float","Double","Literal"};
	
	for (int i = 0; i < 5 ; i++)
	{
		if (checkType[i](value) == true)
		{
			std::cout<<"hemos parado en :"<<type[i]<<std::endl;
			break;
		}
	}
	/*if (value.empty())

		std::cout<<"empty"<<std::endl;
	if(ScalarConverter::checkChar(value))
		std::cout<<"CHAR"<<std::endl;
	if(ScalarConverter::checkInt(value))
		std::cout<<"INT"<<std::endl;
	if(ScalarConverter::checkFloat(value))
		std::cout<<"FLOAT"<<std::endl;
	if(ScalarConverter::checkDouble(value))
		std::cout<<"DOUBLE"<<std::endl;
	if(ScalarConverter::checkLiteral(value))
		std::cout<<"LITERAL"<<std::endl;
	else
		std::cout<<"ERROR"<<std::endl;*/
}
