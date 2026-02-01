/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:49:55 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/01 21:00:14 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ScalarConverter.hpp"

// int main(int gc, char **gv)
// {
// 	if (gc != 2)
// 	{
// 		std::cout<<"Error: wrong number of arguments"<<std::endl;
// 		return 1;
// 	}
// 	std::string inputStr = static_cast<std::string>(gv[1]);
// 	if (inputStr.empty())
// 	{
// 		std::cout<<"Erorr: empty argument"<<std::endl;
// 		return 1;
// 	}
// 	ScalarConverter::convert(inputStr);
// 	return 0;
// }

int main (void)
{
	std::string s = "42.10119f";
	float f = atof(s.c_str());
	double d = atof(s.c_str());
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << d << std::endl;
}