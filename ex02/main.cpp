/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svolkau <gvardovski@icloud.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 14:37:05 by svolkau           #+#    #+#             */
/*   Updated: 2026/02/02 15:10:20 by svolkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/Base.hpp"
#include "inc/A.hpp"
#include "inc/B.hpp"
#include "inc/C.hpp"

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		Base *obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
	}
	return 0;
}
