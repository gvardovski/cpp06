/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:49:07 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/01 20:44:52 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_CLASS_HPP
#define SCALARCONVERTER_CLASS_HPP

#include <iostream>
#include <limits>
#include <string>
#include <cmath>

enum    e_type
{
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    INVALID = -1
};

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter &operator=(ScalarConverter const &other);
		~ScalarConverter();
		
	public:
	
		static void convert(std::string &literal);
};

e_type findType(std::string &literal);
bool checkIfSpecialLiterals(std::string &literal);
bool checkIfInt(std::string &literal, size_t &len);
bool checkIfChar(std::string &literal, size_t &len);
bool checkIfDouble(std::string &literal, size_t &dot, size_t &len);
bool checkIfFloat(std::string &literal, size_t &dot, size_t &len);

void convertSpecialLiteral(std::string &literal);
void convertChar(std::string &literal);
void convertInt(std::string &literal);
void convertFloat(std::string &literal);
void convertDouble(std::string &literal);

#endif