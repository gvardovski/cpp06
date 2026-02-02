/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:01:23 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/02 14:12:47 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Serializer.hpp"

int main()
{
	Data		data;
	Data		*data_ptr;
	uintptr_t	raw;

	data.n = 42;
	data.str = "Hello, World!";
	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Original Data values: n = " << data.n << ", str = " << data.str << std::endl;

	raw = Serializer::serialize(&data);
	std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

	data_ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized Data address: " << data_ptr << std::endl;
	std::cout << "Deserialized Data values: n = " << data_ptr->n << ", str = " << data_ptr->str << std::endl;

	return 0;
}