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
	if (val[val.length() - 1] != 'f' || dot != 1)
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

void ScalarConverter::changeChar(const std::string val)
{
	int intVal = static_cast<int>(val[0]);

    if (intVal >= std::numeric_limits<int>::min() && intVal <= std::numeric_limits<int>::max()) 
	{
        std::cout << "Original (char): " << val[0] << std::endl;
        std::cout << "As int: " << intVal << std::endl;
    } 
	else 
		std::cout << "Integer value (" << intVal << ") is out of range for int." << std::endl;
    float floatVal = static_cast<float>(val[0]);
    std::cout << "As float: " << floatVal <<"f"<<std::endl;
    double doubleVal = static_cast<double>(val[0]);
    std::cout << "As double: " << doubleVal << std::endl;
}

void	ScalarConverter::changeInt(const std::string val)
{
	
	char* end;
	long valInt = strtod(val.c_str(), &end);
	if (valInt > std::numeric_limits<int>::max() || valInt < std::numeric_limits<int>::min())
	{
		std::cout<<"Integer out of range"<<std::endl;
		exit(0);
	}
	std::cout<<"Char : ";
	if (std::isprint(static_cast<unsigned char>(valInt)))
		std::cout<<static_cast<unsigned char>(valInt)<<std::endl;
	else
		std::cout<<"Not Printable"<<std::endl;
	std::cout<<"Integer : "<<static_cast<int>(valInt)<<std::endl;
	std::cout<<"Float : "<<static_cast<float>(valInt)<<"f"<<std::endl;
	std::cout<<"Double : "<<static_cast<double>(valInt)<<std::endl;
}

void ScalarConverter::changeDouble(const std::string val)
{
	char* end;
    double valDouble = strtod(val.c_str(), &end);
	if (valDouble > std::numeric_limits<double>::max() || valDouble < std::numeric_limits<double>::min()) 
    {
		std::cout<<"Double out of range"<<std::endl;
		exit(0);
	}
	std::cout<<"Char : ";
	if (std::isprint(static_cast<unsigned char>(valDouble)))
		std::cout<<static_cast<unsigned char>(valDouble)<<std::endl;
	else
		std::cout<<"Not Printable"<<std::endl;
	std::cout<<"Integer : "<<static_cast<int>(valDouble)<<std::endl;
	std::cout<<"Float : "<<static_cast<float>(valDouble)<<"f"<<std::endl;
	std::cout<<"Double : "<<static_cast<double>(valDouble)<<std::endl;

	
}

void ScalarConverter::changeFloat(const std::string val)
{
	std::cout<<val<<" coming soon"<<std::endl;
}

void ScalarConverter::changeLiteral(const std::string val)
{
	std::cout<<val<<" coming soon"<<std::endl;
}
void	ScalarConverter::convert (std::string value)
{
	bool		( *checkType[ 5 ] )( const std::string ) = { \
										ScalarConverter::checkChar, \
										ScalarConverter::checkInt, \
										ScalarConverter::checkFloat, \
										ScalarConverter::checkDouble, \
										ScalarConverter::checkLiteral };
	void		(*transform[5])(const std::string) = { \
										ScalarConverter::changeChar, \
										ScalarConverter::changeInt, \
										ScalarConverter::changeFloat, \
										ScalarConverter::changeDouble, \
										ScalarConverter::changeLiteral };
	
	for (int i = 0; i < 5 ; i++)
	{
		if (checkType[i](value) == true)
		{
			transform[i](value);
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
