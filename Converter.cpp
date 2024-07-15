/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josorteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:15:08 by josorteg          #+#    #+#             */
/*   Updated: 2024/07/15 11:01:23 by josorteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*2 checkear que tipo es
	-char
		-1 caracter solo.
		->32 <126 "imprimible"
		- que no sea un digito (seria integer)
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


