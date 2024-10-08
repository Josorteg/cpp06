/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:15:18 by josorteg          #+#    #+#             */
/*   Updated: 2024/07/16 11:27:32 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER__HPP
# define __SCALARCONVERTER__HPP

#include<string>
#include<iostream>
#include<cstdlib>
#include <limits>  
#include <iomanip>

class ScalarConverter
{
	private:
		static bool checkChar(const std::string val);
		static bool checkInt(const std::string val);
		static bool checkFloat(const std::string val);
		static bool checkDouble(const std::string val);
		static bool checkLiteral(const std::string val);
		
		static void changeChar(const std::string val);
		static void changeInt(const std::string val);
		static void changeFloat(const std::string val);
		static void changeDouble(const std::string val);
		static void changeLiteral(const std::string val);

	public:
		
		~ScalarConverter(void);
		static void convert(std::string value);
};
#endif
