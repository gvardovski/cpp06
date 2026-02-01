/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:49:04 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/01 20:44:54 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	*this = other;	
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	static_cast<void>(other);
	return *this;
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string &literal)
{
	e_type type = findType(literal);
	
	switch (type)
	{
	case INVALID:
		std::cout<<"Invalid literal"<<std::endl;
		break;
	case SPECIAL:
		convertSpecialLiteral(literal);
		break;
	case CHAR:
		convertChar(literal);
		break;
	case INT:
		convertInt(literal);
		break;
	case FLOAT:
		convertFloat(literal);
		break;	
	case DOUBLE:
		convertDouble(literal);
		break;	
	}
}	