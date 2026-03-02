/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 14:51:56 by jweber            #+#    #+#             */
/*   Updated: 2026/03/02 15:16:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serialize.hpp"
#include <iostream>
#include <stdint.h>

int	main(void)
{
	Data	d(3,4);
	std::cout << "d: " << d;


	uintptr_t r = Serialize::serialize(&d);
	std::cout << "r (dec) = " << r << "\n";
	std::cout << std::hex << std::showbase;
	std::cout << "r (hex) = " << r << "\n";

	int	*i = reinterpret_cast<int *>(r);
	i[0] += 1;
	i[1] += 1;
	std::cout << std::dec;
	std::cout << "d: " << d;

	Data *d_back = Serialize::deserialize(r);
	std::cout << "*d_back: " << *d_back;
}
