/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:17:30 by josorteg          #+#    #+#             */
/*   Updated: 2024/07/12 10:20:32 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Converter.hpp"

int main (int val,char **values)
{
	if (val != 2)
	{
		std::cout<<"One and only one parameter in the function!!"<<std::endl;
		return (1);
	}
	ScalarConverter::convert(values[1]);
	return (0);
}
