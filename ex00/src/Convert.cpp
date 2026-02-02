/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:54:05 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/02 13:54:47 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

void convertSpecialLiteral(std::string &literal)
{
	if (literal == "nan" || literal == "nanf")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: nanf"<<std::endl;
		std::cout<<"double: nan"<<std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: +inff"<<std::endl;
		std::cout<<"double: +inf"<<std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout<<"char: impossible"<<std::endl;
		std::cout<<"int: impossible"<<std::endl;
		std::cout<<"float: -inff"<<std::endl;
		std::cout<<"double: -inf"<<std::endl;
	}
}

void convertChar(std::string &literal)
{
	std::cout<<"char: ";
	unsigned char ch = static_cast<unsigned char>(literal[0]);
	if (isprint(ch))
	{
		std::cout<<"'"<<ch<<"'"<<std::endl;
		std::cout<<"int: "<<static_cast<int>(ch)<<std::endl;
		std::cout<<"float: "<<static_cast<float>(ch)<<".0f"<<std::endl;
		std::cout<<"double: "<<static_cast<double>(ch)<<".0"<<std::endl;
	}
	else
		std::cout<<"Non displayable"<<std::endl;
}

void convertInt(std::string &literal)
{
	long int val = atol(literal.c_str());
	std::cout<<"char: ";
	if (val < 0 || val > 127)
		std::cout<<"impossible"<<std::endl;
	else if (isprint(val))
		std::cout<<"'"<<static_cast<char>(val)<<"'"<<std::endl;
	else
		std::cout<<"Non displayable"<<std::endl;
	std::cout<<"int: ";
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(val)<<std::endl;
	std::cout<<"float: "<<static_cast<float>(val)<<".0f"<<std::endl;
	std::cout<<"double: "<<static_cast<double>(val)<<".0"<<std::endl;
}

void convertFloat(std::string &literal)
{
	float val = atof(literal.c_str());
	bool presizion = fabs(val - static_cast<int>(val)) < 0.0000000000001;
	std::cout<<"char: ";
	if (val < 0 || val > 127)
		std::cout<<"impossible"<<std::endl;
	else if (isprint(val))
		std::cout<<"'"<<static_cast<char>(val)<<"'"<<std::endl;
	else
		std::cout<<"Non displayable"<<std::endl;
	std::cout<<"int: ";
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(val)<<std::endl;
	std::cout<<"float: ";
	if (val < std::numeric_limits<float>::min() || val > std::numeric_limits<float>::max())
		std::cout<<val<<"f"<<std::endl;
	else
		std::cout << val << (presizion ? ".0f" : "f") << std::endl;
	std::cout<<"double: "<<static_cast<double>(val)<<(presizion ? ".0" : "")<<std::endl;
}

void convertDouble(std::string &literal)
{
	double val = atof(literal.c_str());
	bool presizion = fabs(val - static_cast<int>(val)) < 0.0000000000001;
	std::cout<<"char: ";
	if (val < 0 || val > 127)
		std::cout<<"impossible"<<std::endl;
	else if (isprint(val))
		std::cout<<"'"<<static_cast<char>(val)<<"'"<<std::endl;
	else
		std::cout<<"Non displayable"<<std::endl;
	std::cout<<"int: ";
	if (val < std::numeric_limits<int>::min() || val > std::numeric_limits<int>::max())
		std::cout<<"impossible"<<std::endl;
	else
		std::cout<<static_cast<int>(val)<<std::endl;
	std::cout<<"float: ";
	if (val < std::numeric_limits<float>::min() || val > std::numeric_limits<float>::max())
		std::cout<<val<<"f"<<std::endl;
	else
		std::cout << val << (presizion ? ".0f" : "f") << std::endl;
	std::cout<<"double: ";
	if (val < std::numeric_limits<double>::min() || val > std::numeric_limits<double>::max())
		std::cout<< val <<std::endl;
	else
		std::cout << val << std::endl;
}