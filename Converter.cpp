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
	char* end;
	long valInt = strtod(val.c_str(), &end);
	if (valInt > std::numeric_limits<int>::max() || -valInt < std::numeric_limits<int>::min())
	{
		return(false);
	}
	return(true);
	
}

bool	ScalarConverter::checkFloat(std::string val)
{	
	int dot = 0;
	char* end;
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
	float valDouble = strtod(val.c_str(), &end);
	if (valDouble == std::numeric_limits<float>::infinity() || valDouble == -std::numeric_limits<float>::infinity()) 
    {
		return(false);
	}
	return (true);
}

bool ScalarConverter::checkDouble(const std::string val)
{
	int dot = 0;
	char* end;
	for (size_t i = (0 + (val[0] == '-') + (val[0] == '+'));
			val[i]; i++)
	{
		if (!std::isdigit(val.c_str()[i]) and val[i] != '.' )
			return (false);
		else if (val[i] == '.')
		{
			if (dot > 0)
				return (false);
			dot++;
		}
	}
	long double valDouble = strtod(val.c_str(), &end);
	//std::cout<<valDouble<<std::endl;
	//std::cout<<std::numeric_limits<double>::infinity()<<std::endl;
	if (valDouble == std::numeric_limits<double>::infinity() || valDouble == -std::numeric_limits<double>::infinity())
	{
		std::cout<<"Out of Range Double"<<std::endl;
		exit(0);
	}
	return (true);
}



void ScalarConverter::changeChar(const std::string val)
{
	std::cout << "Original (char): " << val[0] << std::endl;
	int intVal = static_cast<int>(val[0]);
	std::cout << "As int: " << intVal << std::endl;
	float floatVal = static_cast<float>(val[0]);
	std::cout << "As float: " << std::fixed<<std::setprecision(1)<< floatVal <<"f"<<std::endl;
	double doubleVal = static_cast<double>(val[0]);
	std::cout << "As double: " << std::fixed<<std::setprecision(1)<<doubleVal << std::endl;
}

void	ScalarConverter::changeInt(const std::string val)
{
	
	char* end;
	
	long valInt = strtod(val.c_str(), &end);
	int	flag;
	flag = 0;
	if (valInt > std::numeric_limits<int>::max() || -valInt< std::numeric_limits<int>::min())
	{
		flag = 1;
	}
	std::cout<<"Char : ";
	if (valInt > 127 || valInt < 0)
		std::cout<<"Impossible"<<std::endl;
	else if ((valInt < 32) || (valInt > 126 ))
		std::cout<<"Not Printable"<<std::endl;
	else
		std::cout<<"'"<<static_cast<unsigned char>(valInt)<<"'"<<std::endl;
		
	if (flag == 0)
		std::cout<<"Integer : "<<static_cast<int>(valInt)<<std::endl;
	else
		std::cout<<"Integer : Out of range 2"<<std::endl;
	std::cout<< std::fixed<<std::setprecision(1)<<"Float : "<<static_cast<float>(valInt)<<"f"<<std::endl;
	std::cout<< std::fixed<<std::setprecision(1)<<"Double : "<<static_cast<double>(valInt)<<std::endl;
}

void ScalarConverter::changeDouble(const std::string val)
{
	char* end;
    double valDouble = strtod(val.c_str(), &end);
	int valInt = strtod(val.c_str(), &end);
	int	flag = 0;
	int	flag2 = 0;
	std::cout<<valDouble<<std::endl;
	std::cout<<std::numeric_limits<float>::min()<<std::endl;
	if (valDouble > std::numeric_limits<int>::max() || valDouble < std::numeric_limits<int>::min())
	{
		flag = 1;
	}
	if (valDouble > std::numeric_limits<float>::max() || -valDouble > std::numeric_limits<float>::max())
	{
		flag2 = 1;
	}
	std::cout<<"Char : ";
	if (valInt > 127 || valInt < 0)
		std::cout<<"Impossible"<<std::endl;
	else if ((valInt < 32) || (valInt > 126 ))
		std::cout<<"Not Printable"<<std::endl;
	else
		std::cout<<"'"<<static_cast<unsigned char>(valInt)<<"'"<<std::endl;
	if (flag == 0)
		std::cout<<"Integer : "<<static_cast<int>(valDouble)<<std::endl;
	else	
		std::cout<<"Integer : Impossible 3"<<std::endl;
	if (flag2 == 0)
		std::cout<< std::fixed<<std::setprecision(1)<<"Float : "<<static_cast<float>(valDouble)<<"f"<<std::endl;
	else
		std::cout<<"Float : Impossible"<<std::endl;
	std::cout<< std::fixed<<std::setprecision(1)<<"Double : "<<static_cast<double>(valDouble)<<std::endl;

	
}

void ScalarConverter::changeFloat(const std::string val)
{
	char* end;
	char* end2;
    double valDouble = strtod(val.c_str(), &end);
	int	valInt = strtod(val.c_str(), &end2);
	int	flag;
	flag = 0;
	std::cout<<valInt<<std::endl;
	if (valInt == std::numeric_limits<int>::max() || valInt == std::numeric_limits<int>::min())
	{
		flag = 1;
	}
	std::cout<<"Char : ";
	if (valInt > 127 || valInt < 0)
		std::cout<<"Impossible"<<std::endl;
	else if ((valInt < 32) || (valInt > 126 ))
		std::cout<<"Not Printable"<<std::endl;
	else
		std::cout<<"'"<<static_cast<unsigned char>(valInt)<<"'"<<std::endl;
	if (flag == 0)
		std::cout<<"Integer : "<<static_cast<int>(valDouble)<<std::endl;
	else	
		std::cout<<"Integer : Impossible"<<std::endl;
	std::cout<< std::fixed<<std::setprecision(1)<<"Float : "<<static_cast<float>(valDouble)<<"f"<<std::endl;
	std::cout<< std::fixed<<std::setprecision(1)<<"Double : "<<static_cast<double>(valDouble)<<std::endl;
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
void ScalarConverter::changeLiteral(const std::string val)
{
	std::string lastletters;
	std::string val2;
	val2 = val;
	lastletters = val.substr(val.length() -3);
	std::cout<<"Char : Impossible"<<std::endl;
	std::cout<<"Integer : Impossible"<<std::endl;
	if (lastletters == "nff" || lastletters == "anf")
	{
		std::cout<<"Float : "<<val2<<std::endl;
		std::cout<<"Double : "<<val2.erase(val2.length()-1)<<std::endl;
	}
	else
	{
		std::cout<<"Float : "<<val2<<"f"<<std::endl;
		std::cout<<"Double : "<<val2<<std::endl;
	}
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
