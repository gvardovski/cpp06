/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:53:22 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/01 20:16:19 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

bool checkIfSpecialLiterals(std::string &literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "nan" || literal == "+inf" || literal == "-inf")
		return true;
	return false;
}

bool checkIfInt(std::string &literal, size_t &len)
{
	for (size_t i = 0; i < len; i++)
	{
		unsigned char ch = static_cast<unsigned char>(literal[i]);
		if (!isdigit(ch) && !(i == 0 && ch == '-'))
			return false;
	}
	return true;
}

bool checkIfChar(std::string &literal, size_t &len)
{
	unsigned char ch = static_cast<unsigned char>(literal[0]);
	if (len == 1 && !isdigit(ch))
		return true;
	return false;
}

bool checkIfDouble(std::string &literal, size_t &dot, size_t &len)
{
	if (dot == 0 || !isdigit(literal[dot - 1]) || !isdigit(literal[dot + 1]))
		return false;
	for (size_t i = 0; i < len; i++)
	{
		unsigned char ch = static_cast<unsigned char>(literal[i]);
		if ((ch == '.') && i != dot)
			return false;
		if (!isdigit(ch) && !(i == 0 && ch == '-') && (ch != '.'))
			return false;
	}
	return true;
}

bool checkIfFloat(std::string &literal, size_t &dot, size_t &len)
{
	size_t f_pos = literal.find('f');
	if (f_pos == std::string::npos || f_pos != len - 1)
		return false;
	if (!isdigit(literal[f_pos - 1]) || literal[f_pos + 1] != '\0')
		return false;
	if (dot == 0 || !isdigit(literal[dot - 1]) || !isdigit(literal[dot + 1]))
		return false;
	for (size_t i = 0; i < len - 1; i++)
	{
		unsigned char ch = static_cast<unsigned char>(literal[i]);
		if ((ch == '.' && i != dot) || (ch == 'f' && i != f_pos))
			return false;
		if (!isdigit(ch) && !(i == 0 && ch == '-') && (ch != '.') && (ch != 'f'))
			return false;
	}
	return true;
}

e_type findType(std::string &literal)
{
	size_t len = literal.length();
	size_t dot = literal.find('.');
	if (dot == std::string::npos)
	{
		if (checkIfSpecialLiterals(literal))
			return SPECIAL;
		if (checkIfInt(literal, len))
			return INT;
		if (checkIfChar(literal, len))
			return CHAR;
	}
	else
	{
		if (checkIfDouble(literal, dot, len))
			return DOUBLE;
		if (checkIfFloat(literal, dot, len))
			return FLOAT;
	}
	return INVALID;
}