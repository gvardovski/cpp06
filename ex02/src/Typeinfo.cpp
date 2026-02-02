/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Typeinfo.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:59:25 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/02 15:16:10 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base *generate(void)
{
	int random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified A" << std::endl;
		return;
	}
	catch (const std::exception &e) {std::cout << e.what() << std::endl;}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Identified B" << std::endl;
		return;
	}
	catch (const std::exception &e) {std::cout << e.what() << std::endl;}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Identified C" << std::endl;
		return;
	}
	catch (const std::exception &e) {std::cout << e.what() << std::endl;}
}